/* trans command, trial out by Turrican for a commands daemon. */

#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( object *obs ) {
    object ob;

    if( !sizeof( obs = filter( obs, (: living($1) :) ) ) ) {
        write("No-one to transport.\n");
        return 1;
    }

    foreach( ob in obs ) {
        if( ENV(ob) && ENV(ob) == ENV(TP) ) {
            write( WIZ_PRESENT->desc_object(ob)+" is already here.\n");
            continue;
        }

        ob->add_property("last_trans", ({ TP->query_name(),
            ( ENV(ob) ? file_name( ENV(ob) ) : "nullspace") }), 3600 );

        tell_object( ob, "You are magically transferred somewhere.\n");
        ob->move_with_look( ENV(TP), ob->query_mmsgin(), ob->query_mmsgout() );

        if( userp(ob) && ( !ob->query_creator() &&
            !ob->query_property("test character") ) )
            user_event( TP, "inform", TP->query_cap_name()+" transed "+
                ob->query_cap_name()+" to "+file_name(ENV(TP)), "trans");
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() { return ({"<indirect:wiz-present>", (: cmd($1) :) }); }
