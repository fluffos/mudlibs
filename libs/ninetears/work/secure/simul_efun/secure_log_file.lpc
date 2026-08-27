// Originally done by Aragorn
// Tweaked by Radix
#define MAX_LOG_SIZE 200000
#define SECURE_LOG_DIR "/secure/log/"
void secure_log_file( string file, string text )
{
    string logfile;

    if( !stringp( file ) || !stringp( text ) ) return; // syntax error
    if( -1 != strsrch( file, ".." ) ) return; // security error
    if( -1 != strsrch( file, "/" ) ) return; // security error
    logfile = SECURE_LOG_DIR + file; // would 'sprintf' be much better here?
    seteuid("Root");
    if( file_size( logfile ) > MAX_LOG_SIZE )
        rename( logfile, logfile + ".old" );
    write_file( logfile, text );
    if (file == "xp")
      write_file( "/w/baldrick/" + file, text );
   seteuid(0);
}
