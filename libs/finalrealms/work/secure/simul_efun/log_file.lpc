
// Code by Aragorn, who likes his log files...
#define MAX_LOG_SIZE 200000
#define LOG_DIR "/log/"
void log_file( string file, string text )
{
    if( !stringp( file ) || !stringp( text ) ) return; // syntax error
    if( -1 != strsrch( file, ".." ) ) return; // security error
    if( -1 != strsrch( file, "/" ) ) return; // security error
    file = LOG_DIR + file; // would 'sprintf' be much better here?
   seteuid("Root");
    if( file_size( file ) > MAX_LOG_SIZE )
        rename( file, file + ".old" );
    write_file( file, text );
   seteuid(0);
}
