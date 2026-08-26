/* du command, trial out by Turrican for a commands daemon. */

inherit COMMAND_BASE;

protected int rec_du( string path ) {
    string *files, file;
    int size, tot;

    if( path[<1] != '/')
        path += "/";

    files = get_dir( path+"*");

    foreach( file in files ) {
        if( file == "." || file == "..")
            continue;

        file = path + file;
        size = file_size( file );

        if( size > 0 ) {
            tot += size;
        } else if( size == -2 ) {
            printf("%-30s %5d\n", file, ( size = rec_du( file ) ) );
            tot += size * 1024;
        }
    }

    return ( tot + 1023 ) / 1024;

} /* rec_du() */

/** @ignore yes */
int cmd( string path ) {
    if( !path )
        return 0;

    if( master()->valid_read( path, geteuid( TP ) ) ) {
        printf( "%-30s %5d\n", "Total:", rec_du( path ) );
        return 1;
    }

    add_failed_mess("You must have read access to a path to use "
        "du on it.\n");
    return 0;

} /* cmd() */

/** @ignore yes */
mixed query_patterns() {
    return ({ "", (: cmd( TP->query_current_path() ) :),
              "<string'path'>", (: cmd( $4[0] ) :) });
} /* query_patterns() */
