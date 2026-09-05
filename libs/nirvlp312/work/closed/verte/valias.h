/* Updated to player-based aliases */

#include <security.h>

int
cmd_valias(string str)
{
  object  ob;
  mapping aliases;
  int     i, s;
  string  *ks, p;

  if((int)this_player()->query_level() <= APPRENTICE) return 0;
  if(!str) return (notify_fail("View whose aliases?\n"), 0);
  if(!(ob=find_player(str)) || 
   ((int)ob->query_invis() > (int)this_player()->query_level()))
    return (notify_fail("That player isn't online.\n"), 0);
  if((int)ob->query_level() > (int)this_player()->query_level())
    return (notify_fail("That wizard is a higher level than you.\n"), 0);
  aliases = (mapping)ob->query_aliaii();
  if(!aliases || !mapp(aliases) || !sizeof(aliases))
    return (write(capitalize(str) + 
        " doesn't have any aliases currently defined.\n"), 1);
  s = sizeof(ks = keys(aliases));
  write("\n\t\t " + capitalize(str) + "'s Aliases\n");
  write("------------------------------------------------\n");
  for(i = 0; i < s; i ++)
    write("  " + pad((p=ks[i]), 20) + "  " + aliases[p] + "\n");
  write("\n");
  return 1;
}
