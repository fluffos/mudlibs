
inherit COMMAND_BASE;

mapping globals = ([ ]), ret = ([ ]);

#define tp globals[fd]
#define RET ret[fd]

/** @ignore yes */
string *check_perms( string *done, string file ) {
    mixed perm;

    perm = master()->valid_read( file, TP->query_name(), "cat");

    if( !perm || file[<2..] == "/." || file[<3..] == "/..")
        return done;

    if( intp(perm) )
        perm = file;

    return done + ({ perm });

} /* check_perms() */

/** @ignore yes */
mixed cmd( string arg ) {
    int fd, search = 0, nfiles = 0;

    if( !arg ) {
        arg = "";
    } else {
        string bit, *bits;

        bits = explode( arg, " ") - ({""});
        arg = "";

        foreach( bit in bits ) {
            string *files, file;

            if( bit[0] == '-') {
                arg += " " + bit;
                continue;
            }

            if( !search ) {
                search = 1;
                arg += " " + bit;
            } else {
                files = TP->get_files(bit);
                files = implode( files, (: check_perms :), ({ }) );
                foreach( file in files ) {
                    arg += " " + file[1..];
                    nfiles++;
                }
            }
        }
    }

    if( nfiles || !search )
        fd = external_start( 6, arg, "read_call_back",
            "write_call_back", "close_call_back");
    else
        return notify_fail("Grep needs at least one file.\n");

    if( fd == -1 )
        return notify_fail("Grep failed for some reason.\n");

    tp = TP;
    RET = "";

    return 1;

} /* cmd() */

/** @ignore yes */
void read_call_back( int fd, mixed mess ) {
    mess = replace( mess, "/usr/bin/", "");
    RET += mess;
} /* read_call_back() */

/** @ignore yes */
void write_call_back( int fd ) {
    tell_object( tp, "Grep: Whoops! Fatal error.\n");
} /* write_call_back() */

/** @ignore yes */
void close_call_back( int fd ) {
    if( RET != "")
        tp->more_string(RET);
    else
        tell_object( tp, "Grep finished without results.\n");

    map_delete( ret, fd );
    map_delete( globals, fd );

} /* write_call_back() */
