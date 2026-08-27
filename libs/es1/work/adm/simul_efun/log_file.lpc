// log_file.c
// by Annihilator (1-8-94)
#include <config.h>

int log_file( string file, string message )
{
         seteuid(getuid(previous_object()));
	if( write_file( LOG_DIR + file, message ) ) return 1;
	return 0;
}
