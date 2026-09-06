#include <const.h>

#define MAX_FILE_SIZE 8192

#define TRUE 1
#define FALSE 0

int process_codes;
int do_count;
int list_count;
int start, end;

int draw_page( string file, int line_start, int num_lines ) {
    string out, tmp, *line;
    int i, size;

    out = cleanup_string(read_file( file, line_start, num_lines ));

    if(!out) return 0;

    /*
     * Edited by kasey (May 24th)
     * Added two options for line counting.  One
     * displays the file with line numbers the other
     * takes two numbers and displays the lines in
     * range.
     * TODO: Use a better argument parsing method other
     * then sscanf().
     */

    /* And begin sloppy code */
    line = explode( out, "\n" );
    size = sizeof( line );

    /* Just display the lines with numbers */
    if ( do_count == TRUE ) {

       /*
        * Fixed this to make it run faster because I was
        * calling sizeof() for how ever many lines there
        * are making it run slower.
        */

        for( i = 0; i < size; i++ ) {
            tmp = sprintf( "%5d %s\n", i + 1, line[i] );
            (process_codes == TRUE) ? write( process_ansi(tmp) ) : write ( tmp );
        }
        return 1;
    } else {
        if ( list_count == TRUE ) {
            /* Same speed issue here. */
            if ( start > size || end > size || start >= end ) {
                msg( "Line numbers must exist and start must not be greater then end." );
                return -1;
            } else {
                if( start < 1 ) {
                    msg( "line index should not be less then 1.\n");
                    return -1;
                }
                for ( i = start - 1; i < end; i++ ) {
                    tmp = sprintf( "%5d %s\n", i + 1, line[i] );
                    (process_codes == TRUE) ? write( process_ansi(tmp) ) : write ( tmp );
                }
            }
            return 1;
        } else
            (process_codes == TRUE) ? write ( process_ansi(out) ) : write ( out );
    }
    return 1;
    /* End */
}

int main(string param) {
    string file_name, *opt;
    int size;

    WIZ_CHECK

    process_codes = FALSE;
    do_count = FALSE;
    list_count = FALSE;

    if( !param ) {
	notify_fail("==> [Format] cat [-p] [-n] [-l start end] filename\n");
	return 0;
    }

    /* Acius is so smart! :) */
    while( 1 ) {
        if( sscanf( param, "-l %d %d %s", start, end, param) == 3 ) { list_count = TRUE; continue; }
        if( sscanf( param, "-n %s", param) == 1 ) { do_count = TRUE; continue; }
        if( sscanf( param, "-p %s", param) == 1 ) { process_codes  = TRUE; continue; }
        break;
    }

    file_name = this_player()->make_path_absolute( param );
    if( !file_name ) {
	notify_fail("==> [Error] make_path_absolute failed.\n");
	return 0;
    }
    if( !legal_filename(file_name) ) {
	notify_fail("==> [Error] '"+file_name+"' is not a legal file name.\n");
	return 0;
    }
    size = file_size( file_name );
    if( size < 0 ) {
	notify_fail("==> [Error] Can't open the file "+file_name+" for reading.\n");
	return 0;
    }
    if( size > MAX_FILE_SIZE && list_count == FALSE) {
	notify_fail("==> [Error] Cannot list files over "+(MAX_FILE_SIZE/1024)+"K using cat. Use 'more' instead.\n");
	return 0;
    }
    if( size == 0 ) {
	notify_fail("==> File is empty.\n");
	return 0;
    }

    if( draw_page( file_name, 1, 0 ))
	msg("~[090<EOF>~CDEF");
    else
	msg("==> [Error] Access denied");
    return 1;
}
