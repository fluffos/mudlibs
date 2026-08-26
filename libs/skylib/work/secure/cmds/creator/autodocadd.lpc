
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    string *files;

    if( !sizeof( files = TP->get_files(str) ) )
        return notify_fail("Cannot find "+str+" to add.\n");

    foreach( str in files ) {
        if( AUTODOC_H->add_file(str) ) {
            write("Added file "+str+".\n");
            continue;
        }
        write("Unable to add file "+str+".\n");
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<string>", (: cmd($4[0]) :) });
} /* query_patterns() */
