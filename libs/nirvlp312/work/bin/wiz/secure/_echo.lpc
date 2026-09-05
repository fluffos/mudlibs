#include <security.h>

int cmd_echo(string str)
{
 if((int)this_player()->query_level() < ECHO)
  return 0;
 if(!str)
 {
  write("Usage: 'echo <msg>'\n");
  return 1;
 }
 say(str+"\n");
 write("You echo: "+str+"\n");
 return 1;
}
