// What driver ? what options ? what defs ?
// _has.c

#include <mudlib.h>

inherit DAEMON ;

int cmd_has(string str) {

#ifdef HAS_CACHE_STATS
 write("HAS_CACHE_STATS defined\n");
#else
 write("NO HAS_CACHE_STATS\n");
#endif

#ifdef HAS_DEBUGMALLOC
 write("HAS_DEBUGMALLOC defined\n");
#else
	write("NO HAS_DEBUGMALLOC\n");
#endif

#ifdef HAS_DEBUG_LEVEL
	 write("HAS_DEBUG_LEVEL defined\n");
#else
		write("NO HAS_DEBUG_LEVEL\n");
#endif

#ifdef HAS_EACH
	 write("HAS_EACH defined\n");
#else
	write("NO HAS_EACH\n");
#endif

#ifdef HAS_ED
	 write("HAS_ED defined \n");
#else
	write("NO HAS_ED\n");
#endif

#ifdef HAS_MATH
	 write("HAS_MATH defined\n");
#else
	write("NO HAS_MATH\n");
#endif

#ifdef HAS_MATRIX
 write("HAS_MATRIX defined\n");
#else
 write("NO HAS_MATRIX\n");
#endif

#ifdef HAS_OPCPROF
 write("HAS_OPCPROF defined\n");
#else
	write("NO HAS_OPCPROF\n");
#endif

#ifdef HAS_PRINTF
 write("HAS_PRINTF defined\n");
#else
write("NO HAS_PRINTF\n");
#endif

#ifdef HAS_PRIVS
	 write("HAS_PRIVS defined\n");
#else
	write("NO HAS_PRIVS\n");
#endif

#ifdef HAS_RUSAGE
 write("HAS_RUSAGE defined\n");
#else
 write("NO HAS_RUSAGE\n");
#endif

#ifdef HAS_SHADOWS
 write("HAS_SHADOWS defined\n");
#else
 write("NO HAS_SHADOWS\n");
#endif

#ifdef HAS_SOCKETS
 write("HAS_SOCKETS defined\n");
#else
	write("NO HAS_SOCKETS\n");
#endif

#ifdef USE_EUID
 write("USE_EUID defined\n");
#else
	write("NO USE_EUID\n");
#endif

#ifdef HAS_UIDS
 write("HAS_UIDS defined\n");
#else
 write("NO HAS_UIDS\n");
#endif

#ifdef HAS_UIDS
 write("HAS_UIDS defined\n");
#else
	 write("NO HAS_UIDS\n");
#endif

#ifdef HAS_MUDLIB_STATS
	 write("HAS_MUDLIB_STATS defined\n");
#else
	 write("NO HAS_MUDLIB_STATS\n");
#endif

#ifdef HAS_NEW_FUNCTIONS
 write("HAS_NEW_FUNCTIONS defined\n");
#else
 write("NO HAS_NEW_FUNCTIONS\n");
#endif

#ifdef HAS_LIGHT
 write("HAS_LIGHT defined\n");
#else
 write("NO HAS_LIGHT\n");
#endif

#ifdef HAS_LOG_CATCHES
 write("HAS_LOG_CATCHES defined\n");
#else
 write("NO HAS_LOG_CATCHES\n");
#endif

return 1;
}

int help() {

	write("Returns all driver defines that are compiler dependand.\n");
	write("Usually set through the options.h file\n");
	}

