
#include <mudlib.h>

inherit DAEMON;

int cmd_debugmalloc(string str) {
  int i;

#ifdef HAS_DEBUGMALLOC
  if (!str || !sscanf(str, "%d", i)) i = 0;
  debugmalloc("/MALLOC_DUMP", i);
#else
  write("Sorry, this driver has not been compiled with DEBUGMALLOC.\n");
#endif

  return 1;
}
