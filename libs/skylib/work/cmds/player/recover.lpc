/**
 * This method allows you to recover items from the room.
 * @author Pinkfish
 * @started Mon Feb  7 01:04:04 PST 2000
 * @change Changed to use the burial handler - Sandoz, 2002.
 */

#include <obj_parser.h>
#include <move_failures.h>

inherit COMMAND_BASE;

int cmd_recover( string name ) {
    object *obs;
    object *fail;
    object *ok_me;
    object *ok_here;
    object cont;
    object ob;
    mixed stuff;
    string sh;
    class obj_match omatch;

    if( !( cont = BURIAL_H->query_buried_container( ENV(TP) ) ) ||
        !sizeof( INV(cont) ) ) {
        add_failed_mess("There is nothing buried here.\n");
        return 0;
    }

    omatch = match_objects_in_environments( name, cont );
    if( omatch->result != OBJ_PARSER_SUCCESS ) {
        add_failed_mess( match_objects_failed_mess(omatch) );
        return 0;
    }

    obs = omatch->objects;
    fail = ({ });
    ok_me = ({ });
    ok_here = ({ });

    if( sizeof(obs) ) {
        // Recover them...
        foreach( ob in obs ) {
          if( ob->move(TP) == MOVE_OK )
              ok_me += ({ ob });
          else if( ob->move( ENV(TP) ) == MOVE_OK )
              ok_here += ({ ob });
          else
              fail += ({ ob });

          if( ob->query_property("dropped")) {
              stuff = ob->query_property("dropped");
              if( TP->query_name() != stuff[0] &&
                  query_ip_number(TP) == stuff[1] &&
                  sizeof( "/handlers/multiplayer"->check_allowed(
                  TP, ({ stuff[0] }) ) ) ) {
                  sh = TP->query_cap_name()+" recovered "+
                       ob->query_short()+" from "+stuff[0]+" who logged "
                       "in from the same IP address.";
                  user_event("inform", sh, "multiplayer");
                  log_file("MULTIPLAYERS", ctime(time())+": "+sh+"\n");
              } else if( TP->query_name() == stuff[0] &&
                  TP->query_refresh_time() > stuff[2] ) {
                  sh = TP->query_cap_name()+" recovered "+
                       TP->HIS+" equipment after a refresh.";
                  user_event("inform", sh, "multiplayer");
                  log_file("MULTIPLAYERS", ctime(time())+": "+sh+"\n");
              }
          }
        }

        if( !sizeof(ok_me) && !sizeof(ok_here) ) {
            add_failed_mess("Unable to recover $I.\n", fail );
            return 0;
        }

        if( sizeof(ok_me) ) {
            add_succeeded_mess("$N $V $I.\n", ok_me );
        }

        if( sizeof(ok_here) ) {
            add_succeeded_mess("$N $V $I and leave$s "+( query_group(ok_here) ?
                "them" : "it")+" here.\n", ok_here );
        }

        BURIAL_H->event_recover( ENV(TP) );
        return 1;

    } else {
        ok_me = INV(cont);
        if( sizeof(ok_me) ) {
            add_failed_mess("Unable to recover "+name+", available "
                "objects are "+query_multiple_short(ok_me)+".\n");
        } else {
            add_failed_mess("Unable to recover "+name+".\n");
        }
        return 0;
    }
} /* cmd_recover() */

mixed query_patterns() {
    return ({ "<string'buried object'>", (: cmd_recover($4[0]) :) });
} /* query_patterns() */
