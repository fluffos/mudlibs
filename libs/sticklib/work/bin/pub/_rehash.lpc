#include <cmd.h>
#include <daemons.h>

nomask int
rehash_cmd(string str)
{
    if (!CHECK) return 0;

    if (str) {
	if (!this_player()->query_coder_level()) {
	    notify_fail("No arguments allowed for you.\n");
	    return 0;
	}
	if (!CMD_D->rehash( str=(string)this_player()->absolute_path(str) )) {
	    printf( "Failed to rehash directory '%s'.\n", str );
	    return 1;
	}
    }
    this_player()->rehash_commands();
    write( "Ok.\n" );
    return 1;
}
