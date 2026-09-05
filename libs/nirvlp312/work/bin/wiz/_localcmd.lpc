
#include <security.h>

int cmd_localcmd()
{
 if((int)this_player()->query_level() < CREATE)
  return 0;

 localcmd();
 write("\n");
 return 1;
}
