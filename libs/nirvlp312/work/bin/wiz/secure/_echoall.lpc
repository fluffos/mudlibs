#include <security.h>

int cmd_echoall(string str)
{
 object *p;
 int    x;
 if((int)this_player()->query_level() < ECHO)
  return 0;

 if(!str)
 {
  write("Usage: 'echoall <msg>'\n");
  return 1;
 }

 x = sizeof(p = users());

 while(x --)
  if(p[x] && !p[x]->query_muffled() && !in_editor(p[x]))
   tell_object(p[x], str + "\n");

 write("To EVERYBODY, you echo: "+str+"\n");
 return 1;
}
