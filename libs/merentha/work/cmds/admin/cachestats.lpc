// Petrarch
// Merentha Lib 1.0
// <cachestats>

varargs int command(string obj) {
#ifndef __CACHE_STATS__
  message("command", "Cache stats were not compiled in with the driver.",this_player());
#else
  message("command", cache_stats(), this_player());
#endif
  return 1;
}

string help() {
return "Syntax: cachestats\n\nDisplays information on the call_other() cache hit rate.\n\nSee also: mudstats, getconfig";
}
