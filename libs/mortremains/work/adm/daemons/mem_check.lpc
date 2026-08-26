// Memory checking daemon
// Written by Mobydick@TMI-2 on 10-16-93.
// The idea for this, at least locally, is due to Purdy@TMI-2, though
// I'm sure dozens of people have coded something similar.
// Periodically checks the mud's memory usage. If it's too high, begins
// a shutdown.
// We start the shutdown via the shutdown daemon instead of just
// shutting down right away. That way you get the nice messages and
// warn people.
// Leto changed it to use logs.h

#include <mudlib.h>
#include <daemons.h>
#include <logs.h>

inherit DAEMON ;

void check_mem() ;

#define MEM_LIMIT 10000000
#define CHECK_TIME 1200

void create() {
	::create() ;
	check_mem() ;
}

void check_mem() {
	if (MEM_LIMIT<memory_info()) {
	    SHUTDOWN_D->start_shutdown(0,15) ;
	    log_file (SHUTDOWN_LOG, "Memory usage daemon started shutdown at "+ctime(time())+".\n") ;
	    message ("shutdown", "Ramchecker shouts: We are using too much memory! The world will end in 15 minutes!\n",users()) ;
	}
	call_out("check_mem",CHECK_TIME) ;
}

// This is sort of important.

void clean_up() {
	return 0 ;
}
