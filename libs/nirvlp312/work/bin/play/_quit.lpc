#include <security.h>
int cmd_quit(string str)
{
  if(str) return 0;
  if((int)this_player()->query_level() < CREATE)
    this_player()->quit();
  else
    this_player()->do_quit();
  return 1;
}
