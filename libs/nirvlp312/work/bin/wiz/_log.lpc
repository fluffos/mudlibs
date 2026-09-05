#include <security.h>

int cmd_log(string str)
{
 if((int)this_player()->query_level() < CREATE)
  return 0;
 if (!str) str = (string)this_player()->query_real_name();
  if (file_size("/log/"+str) < 1)
  {
    write("Log does not exist: "+str+"\n");
    return 1;
  }
  tail("/log/"+str);
 return 1;
}
