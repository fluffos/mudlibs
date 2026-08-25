// backup.c -- Automagically creates a backup file
// Code originally by Mordred, around 1 May 96
// 06 May 96  Agamemnon  Added file informs
//                       Also added EDIT logging
//                       Thirdly, added support for multiple files
//                       Finally cleaned it up and added more descriptive fails
// 06 June 96  Agamemnon  Changed to use the "cp" efun instead of read
//                        and write_file... (faster, and less chance
//                        to barf and die)

#include <standard.h>
#include <cmd.h>

#define COL ""

inherit CMD_BASE ;

void setup()
  {
  position = 1 ;
}

string get_date() {
    string date;
    int i;
    date = ctime( time() ) ;
    i = member_array( date[ 4..6 ], ({ "Jan", "Feb", "Mar", "Apr", "May",
      "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" }) ) ;
    i++ ;
    date = date[ 22..23 ] + i + date[ 8..9 ] ;
    if( strlen( date ) == 5 ) date = date[ 0..1 ] + "0" + date[2..4];

    date = replace( date, " ", "0" );
    return date;
}

protected int cmd( string str, object me )
{
    string *files, orig, backup, date;
    int i, ver;

    if( this_player( 0 ) != this_player( 1 ) )
    {
        return 0 ;
    }
    if( !str )
    {
        notify_fail( "Usage : backup <filename>\n" ) ;
        return 1 ;
    }

    date = get_date();
    files = this_player()->get_files( str );
    if ( !sizeof( files ) ) {
        write( "Cannot find file(s): "+str+".\n" );
        return 1;
    }

    date = get_date();

    for ( i=0; i<sizeof( files ); i++ ) {
        orig = files[i];
        if ( file_size( orig ) == -1 ) {

            write( "Cannot back up file "+orig+
                   ": No such file or directory.\n" );
            continue;
        }
        if ( file_size( orig ) == -2 ) {
            write( "Cannot backup file "+orig+
                   ": Is a directory.\n" );
            continue;
        }
        backup = orig + "." + date + "."+this_player()->query_name();
        if ( file_size( backup ) == -2 ) {
            write( "Cannot backup to "+orig+
                   ": Is a directory.\n" );
            continue;
        }
        if ( file_size( backup ) != -1 ) {
            ver=2;
            while( file_size( backup + "v" + i ) > 0 ) i++;
            backup += "v" + i;
        }
        if ( cp( orig, backup ) ) {
            write( COL + "File "+orig+" backed up to "+ backup+"\n" );

        } else {
            write( "Unable to write file : "+backup+"\n" );
        }
    }
    return 1 ;
}

