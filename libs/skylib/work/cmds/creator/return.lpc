/**
 * Returns the person you've transed to their previous location.
 * @author Windy, Feb '01
 * @changed Changed to use wiz-present and work with multiple targets.
 * - Sandoz, Nov. 2002.
 */

#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *obs ) {
    object ob;
    int ret;

    foreach( ob in obs ) {
        string *tmp;

        if( !sizeof( tmp = ob->query_property("last_trans") ) ) {
            add_failed_mess( WIZ_PRESENT->desc_object(ob)+" has not been "
                "transed recently.\n");
            continue;
        }

        if( file_name( ENV(ob) ) == tmp[1] ) {
            add_failed_mess( WIZ_PRESENT->desc_object(ob)+" is already at "+
                ob->HIS+" return location.\n");
            continue;
        }

        ret = 1;

        ob->add_property("last_trans", ({ TP->query_name(),
            ( ENV(ob) ? file_name( ENV(ob) ) : "nullspace") }), 3600 );

        tell_object( ob, "You are magically returned to where you came "
            "from.\n");

        ob->move_with_look( tmp[1], ob->query_mmsgin(), ob->query_mmsgout() );

        write( WIZ_PRESENT->desc_object(ob)+" has been returned.\n");

    }

    return ret;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({"<indirect:wiz-present>", (: cmd($1) :) }); }
