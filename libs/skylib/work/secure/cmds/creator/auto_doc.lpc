
inherit COMMAND_BASE;

/** @ignore yes */
int cmd( string str ) {
    string *files;

    if( !sizeof( files = TP->get_files(str) ) )
        files = ({ str });

    foreach( str in files ) {
        if( AUTODOC_H->recreate_documentation(str) ) {
            write("Recreating documentation for "+str+".\n");
            continue;
        }
        write("Unable to recreate documentation for "+str+".\n");
    }

    return 1;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({"<string>", (: cmd($4[0]) :) });
} /* query_patterns() */
