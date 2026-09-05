#include <ansi.h>

int cmd_battle(string str)
{
  string npc, npc2;
  object o, o2;

  if(!str || sscanf(str,"%s %s",npc,npc2) != 2)
  {
    write("Syntax: 'battle <npc1> <npc2>'\n");
    return 1;
  }
  npc = lower_case(npc); npc2 = lower_case(npc2);
  o = present(npc,environment(this_player()));
  o2 = present(npc2,environment(this_player()));
  if(!o || !o2)
  {
    write("One of them isn't here...\n");
    return 1;
  }
  if(!living(o) || !living(o2))
  {
    write("One of them isn't alive...\n");
    return 1;
  }
   write("Forcing "+BOLD+capitalize(npc)+
     NORM+" to attack "+BOLD+capitalize(npc2)+NORM+" -\n");
   this_player()->remote_say(
     (string)this_player()->query_name()
     +" waves his hand and "+
     (string)o->query_name()+" attacks "+
     (string)o2->query_name()+"!\n");
   o->attack_object(o2);
   return 1;
}
