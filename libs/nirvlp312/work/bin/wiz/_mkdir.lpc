#include <security.h>

int cmd_mkdir(string str)
{
 if((int)this_player()->query_level() < CREATE)
  return 0;

 if(!str)
 {
  write("Usage: 'mkdir <directory>'\n");
  return 1;
 }

 mkdir(str);
 return 1;
}

