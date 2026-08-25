//    /cmds/skills/_deus.c
//    Nightmare Mudlib
//    A command for clerics to bless stuff.
//    by Manny@Nighmtare 940906

#include <std.h>

inherit DAEMON;

int cmd_bless(string str) {
  object me, it;
  int mps;
  
  me = this_player();
  if(!str) return notify_fail("Bless what?\n");
  if((!it = present(str, me)) &&
     (!it = present(str, environment(me))))
     return notify_fail("You dont see that here.\n");
  if(environment(me)->query_property("no magic"))
    return notify_fail("Your concentration is being blocked.\n");
  if((string)me->query_class() != "cleric")
    return notify_fail("You mumble incoherantly.");
  if((int)me->query_skill("faith") < random(6)+24)
    return notify_fail("The gods scoff at your feeble attempt to "
       "communicate with them.\n");
  if((int)me->query_skill("healing") < random(9)+10)
    return notify_fail("You lack the expirence to cast the spell.\n");
  mps = random(10)+20;
  if((int)me->query_mp() < mps) 
    return notify_fail("You are too fatigued.\n");
  if(!random(2)) return notify_fail("Nothing happens.\n");
  message("my_action", it->query_cap_name()+" glows faintly.", 
    environment(me));
  it->set_property("blessed", 1);
  me->add_mp(-mps);
  return 1;
}

void help() { 
  message("help", "Command: bless [object]\n\nMutter a prayer of "
      "blessing for an object.", this_player());
  return;
}


