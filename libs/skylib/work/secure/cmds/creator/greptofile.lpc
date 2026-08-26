
inherit __DIR__ "grep";

#define tp globals[fd]
#define RET ret[fd]

int cmd( string arg ) {
    string dir;

    dir = "/w/"+TP->query_name();

    if( file_size(dir) != -2 )
        return notify_fail("Directory: "+dir+" does not exist.\n");

    return ::cmd( arg );

} /* cmd() */

/** @ignore yes */
void read_call_back( int fd, mixed mess ) {
    mess = replace( mess, "/usr/bin/", "");
    if( !pointerp(RET) )
        RET = ({ });
    RET += ({ mess });
} /* read_call_back() */

/** @ignore yes */
void close_call_back( int fd ) {
    string dir, str;

    dir = "/w/"+tp->query_name()+"/grep_result.txt";

    if( sizeof(RET) ) {
        rm(dir);
        foreach( str in RET )
            write_file( dir, str );
        tell_object( tp, "Grep results logged to "+dir+".\n");
    } else
        tell_object( tp, "Grep finished without results.\n");

    map_delete( ret, fd );
    map_delete( globals, fd );

} /* write_call_back() */
