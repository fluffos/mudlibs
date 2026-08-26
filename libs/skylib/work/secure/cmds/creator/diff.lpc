
#include <creator.h>

#define tp globals[fd]
#define FILE files[fd]
#define RET ret[fd]

mapping globals = ([ ]), files = ([ ]), ret = ([ ]);

/** @ignore yes */
int cmd( string arg ) {
    string last, bit, *bits;
    int fd, num;

    if( !arg )
        return notify_fail("Usage: diff <filename1> <filename2>\n");

    last = "";

    bits = explode( arg, " ");

    arg = "";
    bits -= ({""});

    foreach( bit in bits ) {
        string full;
        mixed *st;

        if( bit[0] == '-') {
            last = bit;
            continue;
        }

        bit = ( full = TP->get_path(bit) )[1..];

        if( bit == "")
            return notify_fail("Your wombles just expired.\n");

        if( !master()->valid_read( bit, TP, 0 ) )
            return notify_fail("Permission denied: "+full+".\n");

        if( sizeof( st = unguarded( (: stat, bit :) ) ) ) {
            if( stringp( st[0] ) )
                return notify_fail("You cannot use diff on directories.\n");
        } else {
            return notify_fail("No such file: "+full+".\n");
        }

        arg += " "+last;
        last = bit;
        num++;
    }

    if( num == 2 )
        arg += " "+last;

    last = "/"+last;

    if( num > 3 )
        return notify_fail("You cannot compare more than two files.\n");

    if( num == 3 && file_size(last) > 0 )
        return notify_fail("File "+last+" exists.\n");

    tell_creator("sandoz", "arg: %O", arg );

    fd = external_start( 7, arg, "read_call_back",
         "write_call_back", "close_call_back");

    if( fd == -1 )
        return notify_fail("Diff failed.\n");

    tp = TP;

    if( num == 3 && master()->valid_write( last, TP, 0 ) )
        FILE = last;

    RET = "";
    return 1;

} /* cmd() */

void read_call_back( int fd, mixed mess ) {
    mess = replace( mess, "/usr/bin/", "");
    RET += mess;
} /* read_call_back() */

/** @ignore yes */
void write_call_back( int fd ) {
    tell_object( tp, "Diff: Whoops! Fatal error.\n");
} /* write_call_back() */

/** @ignore yes */
void close_call_back( int fd ) {
    if( FILE ) {
        write_file( FILE, RET );
    } else {
        if( RET == "")
            RET = "These two files are identical.";
        tp->more_string(RET);
    }

    map_delete( ret, fd );
    map_delete( files, fd );
    map_delete( globals, fd );

} /* close_call_back() */
