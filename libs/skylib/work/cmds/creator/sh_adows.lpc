/**
 * Shadows command, trial out by Turrican for a commands daemon.
 * @changed Changed to use query_shadows() efun - Sandoz, Sept. 2002.
 */

#include <creator.h>

inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    object *objs, *shadows, ob;

    if( !str || str == "")
        str = "me";

    if( !sizeof( objs = WIZ_PRESENT->wiz_present( str, TP ) ) ) {
        add_failed_mess("No such object.\n");
        return 0;
    }

    foreach( ob in objs ) {
         shadows = query_shadows(ob);
         if( !sizeof(shadows) ) {
             write( WIZ_PRESENT->desc_f_object(ob)+" is not being "
                 "shadowed.\n");
         } else {
             write( WIZ_PRESENT->desc_f_object(ob)+" is being shadowed "
                 "by:\n");
             map( shadows, (: write("    "+file_name($1)+"\n") :) );
         }
    }

    return 1;

} /* cmd() */
