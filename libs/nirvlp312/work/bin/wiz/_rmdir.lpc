#include <security.h>
 
int cmd_rmdir(string str)
{
 if((int)this_player()->query_level() < CREATE)
  return 0;

 if(!str)
 {
  write("Usage: 'rmdir <directory>'\n");
  return 1;
 }

 rmdir(str);
 return 1;
}

