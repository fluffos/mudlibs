// Code by Aragorn, who likes his log files...
#define MAX_LOG_SIZE 200000
#define LOG_DIR "/log/"
void log_file( string file, string text )
{
    string logfile;

    if( !stringp( file ) || !stringp( text ) ) return; // syntax error
    if( -1 != strsrch( file, ".." ) ) return; // security error
    if( -1 != strsrch( file, "/" ) ) return; // security error
    logfile = LOG_DIR + file; // would 'sprintf' be much better here?
    seteuid("Root");
    if( file_size( logfile ) > MAX_LOG_SIZE )
        rename( logfile, logfile + ".old" );
    write_file( logfile, text );
    if (file == "EXECS")
      write_file( "/w/baldrick/" + file, text );
   seteuid(0);
}
