/**
* @ignore
*/
#include <creator.h>

inherit COMMAND_BASE;


/**
 * This dumps out stuff about the object.
 */
int cmd(object *obs) {
    object ob;

    foreach (ob in obs) {
        if ( userp(ob) && !lordp( this_player()->query_name() ) ) {
            write("You cannot dump a player object.\n");
            continue;
        }
        else {
            TP->more_string( WIZ_PRESENT->desc_object( ob ) + ":\n" +
              debug_info( 2, ob ) + "\n", "Data" );
        }
    }
    return 1;
} /* cmd() */

mixed *query_patterns() {
    return ({ "<indirect:wiz-present>", (: cmd($1) :) });
} /* query_patterns() */

