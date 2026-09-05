#include <security.h>

int cmd_echoto(string str)
{
 object ob;
 string who, msg;
 string it;
 if((int)this_player()->query_level() < ECHO) return 0;
 if(!str || sscanf(str, "%s %s", who, msg) != 2)
 {
  write("Usage: 'echoto <player> <msg>'\n");
  return 1;
 }
 it = lower_case(who);
 ob = find_living(it);
 if(!ob)
 {
  write("No living creature with that name.\n");
  return 1;
 }
 tell_object(ob, msg + "\n");
 write("To "+capitalize(who)+", you echo: "+msg+"\n");
 return 1;
}


