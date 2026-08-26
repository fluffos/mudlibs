
#include <creator.h>

#define WIZ WIZ_PRESENT

inherit COMMAND_BASE;

private string help() {
    return "Usage: inherits <object-id|filename>\n\n"
           "Use wiz_present syntax and/or filename to determine the "
           "inherit tree of a particular item.\n";
} /* help() */

private varargs string parse_inherit_tree( object ob, int level ) {
    string file, mess, *stuff;
    object newob;

    stuff = inherit_list(ob);

    if( !sizeof(stuff) )
        return "";

    mess = "";

    foreach( file in stuff ) {
        if( level )
            mess += sprintf("%*s", level * 2, "");

        mess += file+"\n";

        catch( file->force_load() );

        if( newob = find_object(file) )
            mess += parse_inherit_tree( newob, level+1 );
        else
            mess += sprintf("%*sFAILED TO LOAD %s\n",
                ( level + 1 ) * 2, "", file );
    }

    return mess;

} /* parse_inherit_tree() */

int cmd( string str ) {
    string *filenames, info;
    object ob, *stuff;

    if( !str || str == "")
        return notify_fail(help());

    if( sizeof( filenames = TP->get_cfiles(str) ) )
        stuff = map( filenames, (: load_object($1) :) ) - ({ 0 });
    else if( !sizeof( stuff = WIZ->wiz_present( str, TP ) ) )
        return notify_fail("Can't find "+str+".\n");

    info = "";

    foreach( ob in stuff ) {
        info += "Inherit tree of "+file_name(ob)+" :-\n";
        str = parse_inherit_tree(ob);

        if( !str || str == "")
            info += "No files inherited.\n";
        else
            info += str;
    }

    TP->more_string( info, "Inherits");
    return 1;

} /* cmd() */
