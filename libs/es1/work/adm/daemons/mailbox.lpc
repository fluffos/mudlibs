#pragma save_binary
#define LOCAL_TZONE	"EST"


#define MONITOR_TIME 2500

#include <uid.h>
#include <config.h>
#include <mailer.h>
#include <net/macros.h>

#define QUERY_NAME link_data( "name" )  // XXX: for TMI 1.0 mudlibs

// The following are the variables that will be saved as the datafiles
mapping         *mailbox, my_groups;
nosave  string  file, *dir_list;
nosave  int     maxmsg, dir_idx;


int
valid_access( string frm ) {
  string accessor, *owner;

	if ( !previous_object() ) return 1;
  if( geteuid( previous_object() ) == ROOT_UID )
    return 1;

// Next two ifs check to see if this is a trusted mailer
  accessor = base_name( previous_object() );

  if( member_array( accessor, TRUSTED_MAILERS ) > -1 )
    return 1;

// If a frm == 0 then this is a read operation. If the player may
// always read mail if he is the owner of the box.
  if( file )  {
    owner = explode( file, "/" );
    if( !owner || !owner[sizeof( owner ) - 1] )
      return 0;
    if( (string)this_player()->QUERY_NAME==owner[sizeof(owner)-1] && !frm )
      return 1;
  }

// If frm != 0 then make sure that frm == this_player() to
// prevent forgeries...
  if( frm == ( string ) this_player() -> QUERY_NAME )
    return 1;

  return 0; // Not a legal operation!
} // valid_access


create() {
  seteuid( ROOT_UID );
  mailbox = ({  });
  maxmsg = 0;
  file = 0;
  dir_idx = sizeof( dir_list = get_dir( MBOXDIR ) ) - 1;
  call_out( "monitor_boxes", 10 );
} // create


void
update_box( string owner ) {
  if( file != user_mbox_file( owner ) ) {
    if( file ) {
      if( sizeof( mailbox ) )
         save_object( file );
      else rm( file + SAVE_EXTENSION );
    }

    file = user_mbox_file( owner );
    mailbox = ({  });
    if( file_exists( file + SAVE_EXTENSION ) )
       restore_object( file );
    if( !mailbox )
      mailbox = ({  });
    maxmsg = sizeof( mailbox );
  }
} // update_box


int remote_mail( string rcvr, mapping data ) {
  string own, mud;

  if( sscanf( rcvr, "%s@%s", own, mud ) != 2 )
    return 0;

  if( htonn( mud ) == mud_nname() )
    return 0;

/*
  if( previous_object() != find_object_or_load( NETMAIL_D ) )
     NETMAIL_D -> push_mail( copy( data ) );
*/
  return 1;
} // remote_mail


varargs void
remove_message( string owner, int num ) {
  update_box( owner );

  if( !valid_access( 0 ) )  {
    printf( "Illegal access attempt to mailer_d.\n" );
    return;
  }
  if( num < 0 || num >= maxmsg )
    return;
// remove msg & decrement maxmsg
  MAILMESG_D -> delete_mesg( mailbox[num]["idx"], owner );
  mailbox = mailbox[0 .. num - 1] + mailbox[ num + 1 ..--maxmsg];
} // remove_message


int
add_message( string owner, mapping data ) {
  string own, mud;

  owner = lower_case( owner );
  if( remote_mail( owner, data ) )
    return 1;

  if( !user_exists( owner ) )
    return 0;
  update_box( owner );

  if( !valid_access( data["from"] ) )  {
    printf( "Illegal access attempt to mailer_d.\n" );
    return 0;
  }
  mailbox += ({ data });
  maxmsg++;
  update_box( owner );
  return 1;
} // add_message


mixed
mail_status( string owner ) {
  int cnt, i;

  update_box( owner );
  i = maxmsg;

  while( i-- )  {
    if( !( mailbox[i]["flags"]&MAIL_READ ) )
      cnt++;
  }
  return([  "unread" : cnt, "total" : maxmsg  ]);
} // mail_status


void
set_flags( string owner, int num, int flags ) {
  update_box( owner );

  if( !valid_access( 0 ) )  {
    printf( "Illegal access attempt to mailer_d.\n" );
    return;
  }
  if( num < 0 || num >= maxmsg )
    return;
  if( !mailbox[num]["idx"] ) mailbox[num]["idx"] = mailbox[num]["date"];
  mailbox[num]["flags"] = flags;
} // set_flags


void
biff( string str, string from, string subject ) {
  string        grp, *grparr;
  object        ob;
  int   i;

  if( sscanf( str, "(%s)", grp ) )  {
    grparr = ( ( mapping ) GROUP_OB -> query_groups() )[grp];
    i = sizeof( grparr );
    while( i-- )
      biff( grparr[i], from, subject );
    return;
  }

  if( ( ob = find_player( str ) ) && ( ob -> getenv( "mail_notification" ) ) )
    message( "system", sprintf( "\
      \n>>> New mail has arrived from: %s.\n>>> Subject: %s\n",
      capitalize( from ), subject ), ob );
} // biff


string *
expand_to( mixed str ) {
  string grp, *rtn;
  int i, max;
  mapping grps;
  string t1, t2;

  rtn = ({  });
  i = sizeof( str );

  while( i-- )  {
    if( !str[i] )
      continue;
    str[i] = lower_case( str[i] );

    if( sscanf( str[i], "%s@%s", t1, t2 ) == 2 )    {
      rtn += ({ str[i] });
      continue;
    }

    if( sscanf( str[i], "(%s)", grp ) )    {
      grps = ( mapping ) GROUP_OB -> query_groups();
      if( sizeof( grps[grp] ) )
        rtn += expand_to( grps[grp] );
      else
        printf( "Group `%s' doesn't exist.\n", grp );
      continue;
    }
    if( user_exists( str[i] ) )
      rtn += ({ str[i] });
    else
      printf( "User `%s' not found.\n", str[i] );
  }
  return rtn;
} // expand_to


string *
send_mail( mapping newmsg ) {
  int   i, j;
  string        *tmpto, *rtn, previous;
  mapping       bouncemsg;
  string        mesg;

  newmsg += ([ ]);
  previous = base_name( previous_object() );

  if( !valid_access( newmsg["from"] ) ) {
        log_file( "mailerd", "Illegal access by: " +
                identify( previous_object() ) + "\n" );
        return ({ });
  }

  tmpto = expand_to( newmsg["to"] ) + expand_to( newmsg["cc"] );
  tmpto = uniq_array( tmpto );

  i = sizeof( tmpto );
  rtn = allocate( i );
  j = 0;

  while( i-- ) {
        if( !remote_mail( tmpto[i], newmsg ) )
            rtn[j++] = tmpto[i];
  }

  if( j != sizeof( tmpto ) )
     if( previous_object() != find_object_or_load( NETMAIL_D ) )
        NETMAIL_D -> push_mail( copy( newmsg ) );

  rtn = rtn[0..j - 1];

  mesg = copy( newmsg["message"] );
  map_delete( newmsg, "message" );

  newmsg["idx"] = (int) MAILMESG_D -> add_mesg( rtn, mesg );

  while( j-- )  {
    // Messages coming in from NETMAIL_D look like "<user>@Tabor"
    sscanf( rtn[j], "%s@%*s", rtn[j] );

        // If we fail sending the message to the user on this mud, then
        // we prepare and send out a bounced message report.
    if( !add_message( rtn[j], newmsg ) ) {
		bouncemsg = allocate_mapping( 6 );
           // We have to make a copy because we're still needing newmsg
           // fully intact, and here, we plan towmsg );
           bouncemsg["message"] = "> " +
                replace_string( mesg, "\n", "\n> " );
           bouncemsg[ "message" ] =
                "Date: " + ctime( time() ) + " " LOCAL_TZONE + ".\n" +
                "Message from POSTMASTER@" + Mud_name() + ":\n" +
                "Unable to send to user: " + capitalize( rtn[j] ) +
		"@" + Mud_name() + ".\n\n" +
                read_file( MAIL_BOUNCE_FILE ) +
                "Original Subject: " + newmsg["subject"] + "\n" +
                bouncemsg[ "message" ] +
                "\n**** End of Message ****\n";
           bouncemsg[ "subject" ] = "User \"" + rtn[j] + "\" doesn't exist.";
           bouncemsg[ "date" ] = time();
           map_delete( bouncemsg, "cc" );
           bouncemsg[ "to" ] = ({ newmsg[ "from" ] });
           bouncemsg[ "from" ] = "POSTMASTER";
       log_file( "mailerd", sprintf(
          "%s unable to send to %s\n", newmsg["from"], rtn[j] ) );
           NETMAIL_D -> push_mail( bouncemsg );
           continue;
        }

    call_out( "biff", 0, rtn[j], newmsg["from"], newmsg["subject"] );
  }

  // If i > j, then there's a mud to send to.  First, make sure
  // we aren't the netmail daemon sending us a message to process.
  // We stick this at the end because we don't have to send it immediately,
  // and because otherwise, since netmail does some funky things with
  // the mapping, we'd have to copy() the mapping before we sent if off.
 if( ( previous != NETMAIL_D ) && ( i > j ) )
        NETMAIL_D -> push_mail( newmsg );

  return tmpto;
} // send_mail


int valid_shadow() {
  return 1;
}


void flush_files( mapping groups ) {
   if( !file ) return;
   if( sizeof( mailbox ) )
      save_object( file );
   else
      if( file_exists( file + SAVE_EXTENSION ) )
         rm( file + SAVE_EXTENSION );
}

int
fix_message( string owner, mapping data ) {
  string own, mud;
  string mesg;
  string *tmpto;

  owner = lower_case( owner );
  if( !user_exists( owner ) )
    return 0;
  update_box( owner );

  mesg = copy( data["message"] );
  tmpto = expand_to( data["to"] ) + expand_to( data["cc"] );
  tmpto = uniq_array( tmpto );
  tmpto = filter_array( tmpto, "not_saved", this_object() );
  data["idx"] = (int) MAILMESG_D -> add_mesg( tmpto, mesg );
  map_delete( data, "message" );
  mailbox += ({ data });
  maxmsg++;
  update_box( owner );
  MAILMESG_D -> save_mesg();
  return 1;
} // fix_message

int not_saved( string name ) {
  if( strsrch( name, "@" ) == -1 )
     if( user_exists( lower_case( name ) ) )
        return 1;
  return 0;
}

protected void
remove_box( string owner ) {
   int i;

   update_box( owner );
   i = sizeof( mailbox );
   while( i-- )
      remove_message( owner, i );
   rm( user_mbox_file( owner ) + ".o" );
}

int monitor_boxes() {
  int i, out;
  string *names;
  // debug_message(sprintf("%O", dir_list));
  if (!sizeof(dir_list))
  {
    return 0;
  }

  names = get_dir(MBOXDIR + "/" + dir_list[dir_idx] + "/");
  i = sizeof( names );

  while( i-- ) {
     names[i] = replace_string( names[i], SAVE_EXTENSION, "" );
     if( !user_exists( names[i] ) ) {
         out++;
  message( "debug", "notuser: " + names[i] + "\n",
		find_player( "inspiral" ) );
         remove_box( names[i] );
         continue;
     }
     call_out( "clean_box", 4+(3*i), names[i] );
  }

  if( --dir_idx < 0 )
      dir_idx = sizeof( dir_list = get_dir( MBOXDIR ) ) - 1;

  call_out( "monitor_boxes", MONITOR_TIME );
  return out;
}

int clean_box( string owner ) {
  int i, j;

  update_box( owner );
  i = sizeof( mailbox );
  while( i-- ) {
     if( !file_exists( mail_mesg_file( mailbox[i]["idx"] ) +
                        SAVE_EXTENSION ) ) {
        remove_message( owner, i );
        j++;
     }
  }
  return j;
}

string *verify_mbox( string *whom, int idx ) {
  int i, j;
  string *tmp;

  tmp = ({ });

  i = sizeof( whom );
  while( i-- ) {
    update_box( whom[i] );
    j = sizeof( mailbox );
    while( j-- )
       if( mailbox[j]["idx"] == idx ) {
           tmp += ({ whom[i] });
       }
  }
  return tmp;
}

/* EOF */
