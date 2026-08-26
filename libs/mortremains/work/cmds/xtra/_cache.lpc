// cache.c
// Command to return the cache-stats.
// Original author unknown, Truilkan or Buddha likely candidates.
// Header and help added by Mobydick, 11-21-92. BEAT CAL!
// Added #ifdef , Leto 94-11-11

inherit "std/cmd_m";

int cmd_cache()
{

#ifndef HAS_CACHE_STATS
  write("Driver was compiled without CACHE_STATS!\n");
#else
        cache_stats();
#endif
        return 1;
}

int help() {
	write ("Usage: cache\n\n"+
"Cache returns some interesting if cryptic statistics about the cache.\n") ;
	return 1 ;
}
