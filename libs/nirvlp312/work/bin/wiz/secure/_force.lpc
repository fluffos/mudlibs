#include <security.h>
int cmd_force(string str)
{
  string who, what;
  object ob;
  if((int)this_player()->query_level() < CONTROL)
    return 0;
  if(!str)
  {
    write("Force who to do what?\n");
    return 1;
  }
  if(sscanf(str,"%s %s",who,what)==2)
  {
    if(!(ob=find_player(who)) && !(ob=find_living(who)))
    {
      write("No such living.\n");
      return 1;
    }
    ob->force_us(what);
    write("Ok.\n");
    return 1;
  }
}
