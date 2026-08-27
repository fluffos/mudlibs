#include <command.h>

int main(string str)
{
  string s1, s2;
  object ob;
  if(!str)
    return notify_fail("usage: echoto <player> <text>\n");

  if(sscanf(str,"%s %s", s1, s2) != 2)
    return notify_fail("usage: echoto <player> <text>\n");

  ob = find_player(s1);

  if(!ob)
    return notify_fail("Sorry, that player isn't on-line.\n");

  write(ob->query_cap_name() + " just saw: " + s2 + "\n");

  tell_object(ob, s2+"\n");

  return 1;
}
