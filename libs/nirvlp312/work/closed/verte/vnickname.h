
#include <security.h>

int
cmd_vnickname(string str)
{
  object  ob;
  mapping nicknames;
  int     i, s;
  string  *ks, p;

  if((int)this_player()->query_level() <= APPRENTICE) return 0;
  if(!str) return (notify_fail("View whose nicknames?\n"), 0);
  if(!(ob=find_player(str)) || 
   ((int)ob->query_invis() > (int)this_player()->query_level()))
    return (notify_fail("That player isn't online.\n"), 0);
  if((int)ob->query_level() > (int)this_player()->query_level())
    return (notify_fail("That wizard is a higher level than you.\n"), 0);
  nicknames = (mapping)ob->query_nicknames();
  if(!nicknames || !mapp(nicknames) || !sizeof(nicknames))
    return (write(capitalize(str) + 
        " doesn't have any nicknames currently defined.\n"), 1);
  s = sizeof(ks = keys(nicknames));
  write("\n\t\t " + capitalize(str) + "'s Nicknames\n");
  write("------------------------------------------------\n");
  for(i = 0; i < s; i ++)
    write("  " + pad((p=ks[i]), 20) + "  " + nicknames[p] + "\n");
  write("\n");
  return 1;
}
