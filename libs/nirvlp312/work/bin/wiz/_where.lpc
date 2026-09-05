#include <security.h>

int cmd_where(string str)
{
 object ob;

 if((int)this_player()->query_level() < EXPLORE)
  return 0;

 if(!str) {
  write("Usage: 'where <player_name>'\n");
  return 1;
 }
 if(!(ob = find_player(str)) && !(ob = find_living(str)) &&
    !(ob = find_object(str)))
 {
  write(capitalize(str)+" not found.\n");
  return 1;
 }

 if(!(ob = environment(ob)))
 {
  write(capitalize(str)+" does not have an environment.\n");
  return 1;
 }

 write(object_name(ob)+"\n"+(string)ob->short()+".\n");
 return 1;
}


