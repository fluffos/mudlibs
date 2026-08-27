//
//      File:                   channels.c  (A daemon)
//      Author:                 Inspiral@Tabor, et al
//      Created:                93-05-10
//      Purpose:                To efficiently handle player communication.
//
// REVISON HISTORY:
// 930725  - Fixed problem with creating spurious channels!    -- Inspiral
// 930801  - Added scan_config()                               -- Inspiral
// 930803  - Reformatted data structure to use
//           more arrays than mappings                         -- Inspiral
// 930811  - Removed all reliances on query() and set() lfuns. -- Inspiral
// 930818  - Added log(), tell_user(), secure()                -- Inspiral
// 930826  - fixed bug in del user                             -- Pallando
// 931004  - added emotes                                      -- Rust
// 940322  - Rewritten to be faster, and to index users by object
//                                                             -- Inspiral
//

#include <channels.h>

int register_channel( string chan, object user, int state );

mapping channels; // contains all our channel stats
mapping alias;  // a rude alias mechanism



// Begin tell_user()
int tell_user( object user, string mesg ) {
    tell_object( user, wrap( sprintf( "CHANNELS:\t%s\n", mesg ) ) );
    return 1;
}
// End tell_user()

// Begin create_channel()
protected
varargs
int create_channel( string chan ) {
    if( channels[chan] ) return 1;

    channels[chan] = ([ ]);
    channels[chan]["vis"] = ({  });
    return 1;
}
// End of create_channel()


// Begin delete_channel()
protected int kill_user( object user, string chan ) {
  if( undefinedp( channels[chan] ) ) return 0;
   channels[chan]["vis"] -= ({ user });
  return 1;
}

protected varargs
int delete_channel( string chan ) {
    if( undefinedp( channels[chan] ) )
        return 0;

    map_delete( channels, chan );
    return 1;
}
// End of delete_channel()


// Beginning of add_user()
protected
varargs
int add_user( string chan, object user) {
    string *toggle_list;
    string priv;

    if( !chan || !user ) return 0;

    if( !pointerp( toggle_list = ( string * ) user-> query( "channels" ) ) ) {
        user-> set( "channels", ({  }) );
        toggle_list = ({  });
    }

// chan doesn't exist...do we have permission to create it?
    if( undefinedp( channels[chan] ) ) {
#ifdef NO_NEW_CHANNELS
        return 0;
#endif
       create_channel( chan, user );
   }

    if( !undefinedp( priv = channels[chan]["priv"] ) )
        if( !member_group( geteuid( user ), priv ) )
            return 0;

    if( member_array( chan, toggle_list ) ==  - 1 )
        user -> add( "channels", ({ chan }) );

   channels[chan]["vis"] =
    uniq_array( channels[chan]["vis"] + ({ user }) );
    return 1;
}
// End of add_user()


protected
int kill_users( mixed chan ) {
  int i;

  if( !chan ) chan = keys( channels );
  else chan = ({ chan });

  i = sizeof( chan );
  while( i-- )
      channels[chan[i]]["vis"] -= ({ 0 });

  return 1;
}


// Beginning of initialize_user()
varargs int initialize_user( object whom ) {
    int i, j;
    object *list;
    string priv;
    string *current_list;

    if( !whom || !living( whom ) ) list = users();
    else list = ({ whom });  // We have one user.

    i = sizeof( list );

    while( i-- ) {
        current_list = ( string * ) list[i] -> query( "channels" );

        if( !pointerp( current_list ) ) {
            list[i]-> set( "channels", ({  }) );
            current_list = ({  });
        }

        j = sizeof( current_list );

    while( j-- )
          register_channel( current_list[j], list[i], ADD );

    }
    return 1;
}
// End of initialize_user()



// Beginning of parse_channel()
varargs int parse_channel( string chan, string mesg, string name, int emote ) {
    int i;
    string *ignore;
    object *list;
    string ext_ob, err, plural;

    if( alias[chan] ) chan = alias[chan];
    if( undefinedp( channels[chan] ) ) return 0;
    kill_users( chan );
    if( undefinedp( ( list = channels[chan]["vis"] ) ) ) return 0;

    i = sizeof( list );  // Optimize is.

// Channel format is wrong in the daemon..Attempt a fix, but log.
    if( !pointerp( list ) ) {
        channels[chan]["vis"] = ({  });
        initialize_user();  // Shall we reconfigure?
        return log_file( sprintf( "parse_channel: channel %s "
          "is not a pointer!  Fixing.", identify( chan ) ) );
    }

// Is the name flag not given? or, is name not even in the list?
    if( this_player() )
        if( member_array( this_player(), list ) ==  - 1 ) return 0;

    if( this_player() && !name )
        name = capitalize((string) this_player() -> query( "name" ));

    if( !mesg || mesg == "" )
       return tell_user( this_player(), "Cannot broadcast blank messages!" );

    if( undefinedp( ( plural = channels[chan]["plural"] ) ) )
        plural = pluralize_verb( chan );

    while( i-- ) {
       if( mesg[0..5] == ":emote" ) {
          mesg = mesg[7..<1];
          emote = 1;
       }

     if( objectp( list[i] ) && list[i]  != this_player() ) {
         ignore = (string *) list[i] -> query( "ignore" );
         if( !pointerp( ignore ) ) ignore = ({ });
         if( member_array( lower_case( name ), ignore ) != -1 ) continue;

         if( list[i]-> getenv( "add_newline" ) )
        tell_object( list[i], "\n" );
     if( emote )
            message( "channels",
              iwrap(capitalize(chan)+": "+name+" "+mesg), list[i]);
            else
            message( "channels",
              iwrap( name + " " + plural + ": " + mesg ), list[i] );
            continue;
        }

        if( list[i] == this_player() )
         if( emote )
            message( "channels",
              iwrap(capitalize(chan)+": "+name+" "+mesg), list[i]);
        else
            message( "channels",
              iwrap( "You " + chan + ": " + mesg ), list[i] );
   } // while()

// Do we have an apply to an external object?
    chan = lower_case( chan );
    if( !undefinedp( ( ext_ob = channels[chan]["object"] ) ) ) {
// format of object flag:  alias#object
        sscanf( ext_ob, "%s#%s", chan, ext_ob );

// Attempt the apply, log all errors
        if( err = catch( ext_ob->
          daemon_apply( this_player(), chan, mesg, emote ) ) )
            log_file( sprintf( "parse_channel:\tError in %s:\n%s",
              ext_ob, err ) );
    }

    return 1;
}
// End of parse_channel()


// Begin of display_channel()
varargs mixed display_channel( string chan, object viewer ) {
    mixed list;

    if( !chan || chan == "" ) list = keys( channels );
    else {
        if( undefinedp( list = channels[chan] ) )
            return sprintf( "There is no such channel:  %s.",
              identify( chan ) );
        list = channels[chan]["vis"];
    }

    if( !pointerp( list ) || !sizeof( list ) ) {
        channels[chan]["vis"] = ({  });
        return sprintf( "CHANNELS:\tNo Users Subscribed to %s",
          identify( chan ) );
    }
    if( chan && chan != "" )
    list = filter_array( list, "flush_list", this_object(), viewer );
    list = map_array( list, "get_cap", this_object() );

    list = ( implode( list, "   " ) + "   <End>" );
    return list;
}
// End of display_channel()


// Begin scan_config()
protected
int scan_config() {
    string *list, *split_line;
    string line;
    int i, j;

    list = update_file( CHANNELS_CONFIG );
    i = sizeof( list );

// Once through the i for each non-"#" line in config file
    while( i-- ) {
        line = list[i];
        if( line ) {
            split_line = explode( line, ":" );
            j = sizeof( split_line );

            channels[split_line[0]] = allocate_mapping( 6 );
            channels[split_line[0]]["vis"] = ({  });

        while( j-- ) {
                if( ( split_line[j] != "X" ) &&
                  ( CHANNELS_INFO[j] != "" ) )
                    channels[split_line[0]][CHANNELS_INFO[j]] =
                      split_line[j];
            } // while (j)

        }  // IF (LINE)
    } // while (i)

    return 1;
}


// Begin log()
int log( string log_mesg ) {
    if( !log_mesg || log_mesg == "" ) return 0; ;

    log_file( CHANNELS_LOG, sprintf( "%s %O - %s\n",
      intl_date_stamp( 1 ), previous_object(), log_mesg ) );
    return 0;
}
// End of log()


mixed q() { return copy( channels );  }
mixed a() { return copy( alias );  }

// Begin process_alias()
void process_alias() {
    int i;
    string *list;
    string temp1;

    list = keys( channels );
    i = sizeof( list );

    while( i-- ) {
        if( !undefinedp( temp1 = channels[list[i]]["object"] ) )
            if( sscanf( temp1, "%s#%*s", temp1 ) == 2 )
                alias += ([ temp1 : list[i] ]);
    }
}

// Begin get_cap()
string get_cap( object ob ) {
   return capitalize((string) ob -> query( "name" ));
}
// End get_cap()

// Begin flush_list()
int flush_list( object user, object viewer ) {
    return (objectp(user) && visible(user, viewer) && interactive(user));
}
// end flush_list()
// Begin create()
void create() {
    channels = allocate_mapping( 20 );
    alias = allocate_mapping( 20 );

    seteuid( getuid() );
    scan_config();
    process_alias();
    call_out( "initialize_user", 2 );
}
// End of create()

// Begin register_channel()
varargs
int register_channel( string chan, object user, int state) {
    int ret;

    if( nullp( state ) ) {
            notify_fail(  "register_channel:  no state given!" );
        return 0;
    }

    switch( state ) {
        case DEL: ret = delete_channel( chan, user ); break;
        case CRE: ret = create_channel( chan, user, state ); break;
        case ADD: ret = add_user( chan, user ); break;
        case KIL: ret = kill_user( user, chan );
        break;
        default: ret = 0; break;
    }
    return ret;
}
// End of register_channel()
