#include <command.h>

int main(string str)
{
  string s1, s2;
  object ob;
  if(!str)
    return notify_fail("usage: force <player> <command>\n");

  if(sscanf(str,"%s %s", s1, s2) != 2)
    return notify_fail("usage: force <player> <command>\n");

  ob = find_player(s1);

  if(!ob)
    return notify_fail("Sorry, that player isn't on-line.\n");

  write(ob->query_cap_name() + " just did: " + s2 + "\n");
  tell_object(ob, "For a split second you are possessed by some spirit.\n");
  
  ob->force_me(s2);

  return 1;
}
