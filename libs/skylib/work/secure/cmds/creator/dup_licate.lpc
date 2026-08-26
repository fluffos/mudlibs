/**
 * This command makes an exact duplicate of an object.
 */

#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
private int cmd( object *obs ) {
    string file;
    object ob, new_ob;
    mixed static_arg, dynamic_arg;

    foreach( ob in obs ) {
        if( !objectp(ob) )
            continue;

        if( !clonep(ob) ) {
            write("Failed to duplicate "+ob->short()+" (not a clone).\n");
            continue;
        }

        file = base_name(ob);
        static_arg = ob->query_static_auto_load();
        dynamic_arg = ob->query_dynamic_auto_load();
        new_ob = clone_object(file);

        if( new_ob ) {
            if( static_arg )
                new_ob->init_static_arg( copy(static_arg) );
            if( dynamic_arg )
                new_ob->init_dynamic_arg( copy(dynamic_arg) );
        }

        if( !new_ob ) {
            write("Failed to duplicate "+ob->short()+" for some reason.\n");
            continue;
        }

        if( !new_ob->move(TP) ) {
            write( new_ob->short()+" duplicated and put in you.\n");
            continue;
        }

        if( !new_ob->move(ENV(TP)) ) {
            write( new_ob->short()+" duplicated and put in here.\n");
            continue;
        }

        if( !new_ob->move("/room/broken") ) {
            write( new_ob->short()+" duplicated and put in /room/broken.\n");
            continue;
        }

        write("Couldn't find any place to put "+new_ob->short()+" in!\n");
        new_ob->move("/room/rubbish");

    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
   return ({"<indirect:wiz-present>", (: cmd($1) :) });
} /* query_patterns() */
