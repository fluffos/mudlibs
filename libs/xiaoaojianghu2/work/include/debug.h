#ifndef DEBUG
#define DEBUG
#endif

#ifdef DEBUG
#define debug(x) if(find_player("nerd")) message("debug",x,find_player("nerd"))
#else
#define debug(x)
#endif
