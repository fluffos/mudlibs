
#include <npc/transport.h>
#include <broadcaster.h>

inherit TRANSPORT_INHERIT;

private nosave string *_colour;
private int _quiet;

/**
 * This method sets the colour of the horse.
 * @param colour the colour of the horse
 */
void set_colour( string colour ) {
    set_short( colour+" horse");
    _colour = explode( colour, " ");
} /* set_colour() */

/** @ignore yes */
string *parse_command_adjectiv_id_list() {
    return ::parse_command_adjectiv_id_list() + _colour;
} /** parse_command_adjectiv_id_list() */

/**
 * This method returns the current colour of the horse.
 * @return the colour of the horse
 */
string query_colour() {
    if( !sizeof(_colour) )
        return "";
    return implode( _colour, " ");
} /* query_colour() */

/**
 * This method sets the quiet flag on the horse.  If they are quiet
 * they will not say anything when they do commands and so on.
 * @param quiet the new value for the quiet flag
 */
void set_quiet( int quiet ) { _quiet = quiet; }

/**
 * This method sets the quiet flag on the horse.  If they are quiet
 * they will not say anything when they do commands and so on.
 * @return the current setting of the quiet flag
 */
int query_quiet() { return _quiet; }

/** @ignore yes */
void hear_name( object player, string mess ) {
    string *bits, str;
    int allowed;

    if( !player )
        return;

    if( is_allowed_to_use( player->query_name() ) ) {
        // Ok, lets see if they asked us to do anything...
        bits = explode( mess, " ") - ({ "" } );
        foreach( str in bits ) {
            switch( str ) {
              case "follow" :
                do_command("follow " + player->query_name() );
              break;
              case "stop" :
                do_command("unfollow " + player->query_name() );
              break;
              case "stay" :
                do_command("unfollow all");
              break;
              case "quiet" :
                set_quiet(1);
              break;
              case "speak" :
              case "talk" :
                set_quiet(0);
              break;
            }
        }

        allowed = 1;

    }

    if( !query_quiet() ) {
        if( allowed )
            do_command("nuzzle " + player->query_name() );

        switch( random(3) ) {
          case 0:
            do_command("whicker");
          break;
          case 1:
            do_command("nicker");
          break;
          case 2:
            do_command("whinny");
          break;
        }
    }

} /* hear_name() */

/** @ignore yes */
void event_person_shout( object thing, string start, string mess, string land,
                         int *co_ord, int range ) {
    if( !thing || ENV(TO)->query_property("shout zone") !=
        ENV(TP)->query_property("shout zone") ) {
        return;
    }

    mess = lower_case(mess);

    if( is_allowed_to_use( thing->query_name() ) ) {
        if( strsrch( mess, lower_case( query_transport_name() ) )  != -1 ) {
            if( strsrch( mess, "come here") != -1 ) {
                if( !query_quiet() )
                    do_command("whicker");
                move_me_to( file_name( ENV(thing) ), 1 );
            }
        }
    }

} /* event_person_shout() */

/** @ignore yes */
void set_transport_name( string name ) {
    ::set_transport_name(name);
    set_determinate("");
} /* set_transport_name() */

/** @ignore yes */
mapping query_dynamic_auto_load() {
    return ([ "::" : ::query_dynamic_auto_load(),
              "colour" : query_colour(),
              "quiet" : query_quiet() ]);
} /* query_dynamic_auto_load() */

/** @ignore yes */
void setup_horse() {
    add_respond_to_with( explode( lower_case( query_transport_name() ), " "),
        (: hear_name :) );

    BROADCASTER->npc_hear_shouts(TO);

    set_short( query_transport_name()+" the "+query_colour()+" horse");
    add_adjective( explode( lower_case( query_transport_name() ), " ") );
    add_alias( lower_case( explode( query_transport_name(), " ")[<1] ) );
    set_determinate("");

} /* setup_horse() */

/** @ignore yes */
void init_dynamic_arg( mapping map ) {
    ::init_dynamic_arg( map["::"] );

    if( map["colour"] )
        set_colour( map["colour"] );

    if( map["quiet"] )
        set_quiet( map["quiet"] );

    if( query_transport_name() )
        setup_horse();

} /* init_dynamic_arg() */

/** @ignore */
int do_name( string name ) {
    if( ::do_name(name) ) {
        setup_horse();
        return 1;
    }

    return 0;

} /* do_name() */
