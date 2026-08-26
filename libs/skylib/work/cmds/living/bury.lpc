#include <move_failures.h>

inherit COMMAND_BASE;

#define GP_INCREMENT 10
#define MAX_BURY_NUMBER 20

int cmd( object *obs ) {
    string person;
    mixed effs, xp;
    object ob, tmp;
    object *sobs;
    object *fobs;
    object *too_many;
    int gp;

    sobs = ({ });
    fobs = ({ });
    too_many = ({ });

    if( TP->query_property("dead") ) {
        add_failed_mess("You're a disembodied spirit, how do you expect to "
            "bury anything at all?\n");
        return 0;
    }

    if( TP->query_fighting() ) {
        add_failed_mess("You cannot bury items while in combat.\n");
        return 0;
    }

    if( ENV(TP)->query_property("no burial") ) {
        add_failed_mess("You cannot bury things here.\n");
        return 0;
    }

    foreach( ob in obs ) {
       if( sizeof(sobs) > MAX_BURY_NUMBER ) {
           too_many += ({ ob });
       } else if( ( ob->get() == MOVE_OK || ob->get() == MOVE_TOO_HEAVY ) &&
           ( ob->query_property("no burial") != 1 ) && !ob->ok_to_bury(TP) ) {
           if( ob->query_property("player") != 1 ||
               ob->query_name() == TP->query_owner() ) {
               // If the weapon is owned, record its burial.
               effs = ob->effects_matching("mudlib.owned.weapon");
               if( sizeof(effs) ) {
                   person = ob->arg_of(effs[0]);
                   log_file("BURIAL", "%s: %s's %s buried by %s\n",
                       ctime(time()), person, ob->query_short(),
                       TP->query_name() );
               }
               BURIAL_H->bury_object( ENV(TP), ob );
               sobs += ({ ob });
               if( ob->query_property("corpse bit") ||
                   ob->query_property("money") ) {
                   gp--;
               } else if( base_name(ob) == "/obj/corpse" &&
                         !ob->query_property("already buried") ) {
                   gp += GP_INCREMENT;
                   ob->add_property("already buried", 1 );
                   // This hands out the rest of the death xp when the object
                   // is buried.
                   xp = ob->query_property("XP");
                   if( xp && sizeof(xp) == 2 ) {
                       foreach(tmp in xp[0]) {
                         if( tmp )
                             tmp->adjust_xp( xp[1], 1 );
                       }
                   }
                   ob->remove_property("XP");
               }
           } else {
               fobs += ({ ob });
           }
       } else {
           fobs += ({ ob });
       }
    }

    if( !sizeof(sobs) ) {
        if( sizeof(fobs) ) {
            if( member_array( TP, fobs ) == -1 ) {
                add_failed_mess("You can't bury "+
                                query_multiple_short(fobs)+".\n");
                return 0;
            } else {
                add_failed_mess("You can't bury "+
                                query_multiple_short(
                                fobs - ({ TP }) + ({"yourself"}) )+".\n");
                return 0;
            }
        } else {
            add_failed_mess("You can't find anything here to bury!\n");
            return 0;
        }
    }

    if( sizeof(too_many) ) {
        write("You can only bury up to "+MAX_BURY_NUMBER+" items at a time, "
              "not burying "+query_multiple_short(too_many)+".\n");
    }

    if( ENV(TP)->query_property("location") != "outside") {
        write("You tidy up the place, clearing away "+
            query_multiple_short(sobs)+".\n");
        say( TP->the_short()+" tidies up the place, clearing away "+
            query_multiple_short(sobs)+".\n");
    } else {
        write("You bury "+query_multiple_short(sobs)+" deep within the "
            "ground.\n");
        say( TP->the_short()+" buries "+query_multiple_short(sobs)+" deep "
            "within the ground.\n");
    }

    TP->adjust_gp(gp);
    return 1;

} /* cmd() */

/**
 * The default bury is to bury corpses.
 */
mixed query_patterns() {
    return ({
        "<indirect:object:here>", (: cmd($1) :),
        "", (: cmd( match_objects_for_existence("corpses", ENV(TP) ) ) :),
        });
} /* query_patterns() */
