#include <std.h>
#include <daemons.h>

inherit DAEMON;
 
int cmd_whirl (string str) {
   int hits, dmg, i, mod;
   object ob, tp, *obz;

   tp = this_player();

   if(!abil())
     return notify_fail("What?\n");

   if(tp->query_ghost())
     return notify_fail("Ghosts cannot harm the living.\n");

   if(environment(tp)->query_property("no attack"))
     return notify_fail("Greater powers prevent your malice.\n");

   if(tp->query_rest_type())
     return notify_fail("You'll need to stand up to attack.\n");

   if(!sizeof(this_player()->query_wielded()))
     return notify_fail("You need a weapon to whirl with!\n");

   if(tp->query_disable())
     return notify_fail("You are too busy already!\n");

   if(tp->query_magic_round())
     return notify_fail("You are already casting a spell.\n");

   if(tp->query_sp() < 20)
     return notify_fail("You are too tired for that.\n");

   if(!ob = present(str, environment(tp)))
     if(!ob = present(tp->query_current_attacker(), environment(tp)))
       return notify_fail("You can't see "+str+" here.\n");

   if(!ob->is_living())
     return notify_fail("This is not the time for target practice.\n");

   if(ob == tp)
     return notify_fail("You whirl at yourself mercilessly.\n");

   if(!tp->kill_ob(ob))
     return notify_fail("You cannot attack "+ob->query_cap_name()+".\n");

     hits = 0;
   if(tp->query_skill("attack") >= (90  + random(10) - random(10)))
     hits++;
   if(tp->query_skill("attack") >= (180 + random(10) - random(10)))
     hits++;
   if(tp->query_skill("attack") >= (270 + random(10) - random(10)))
     hits++;
   if(tp->query_skill("attack") >= (360 + random(10) - random(10)))
     hits++;

   tp->clean_up_attackers();
   obz = tp->query_attackers();
   obz -= ob;
   i = sizeof(obz);
   mod = 10;

   dmg  = tp->query_skill("attack");
   dmg += tp->query_stats("strength")*2;
   dmg -= ob->query_skill("defense")/3;
   dmg -= ob->query_stats("dexterity")/2;

   message("info", "You whirl through the melee.", tp);
   message("info", tp->query_cap_name()+" whirls through the melee.", environment(tp), tp);

   message("info", "You strike "+ob->query_cap_name()+" with a mighty blow.", tp);
   message("info", tp->query_cap_name()+" strikes you deftly.", ob);

   while(hits--) {
     if(!i) {
       obz = tp->query_attackers();
       i = sizeof(obz);
       }
     i--;
     mod -= 2;
     hits--;
     
     dmg  = tp->query_skill("attack");
     dmg += tp->query_stats("strength")*2;
     dmg -= obz[i]->query_skill("defense")/3;
     dmg -= obz[i]->query_stats("dexterity")/2;
     dmg *= mod;
     dmg /= 10;

     if(dmg - obz[i]->query_current_protection() < 1) {
       message("info", ob->query_cap_name()+" dodges your attack!", tp);
       message("info", tp->query_cap_name()+" barely misses an attack on you.", obz[i]);
       continue;
       }

     message("info", "You strike "+obz[i]->query_cap_name()+" deftly.", tp);
     message("info", tp->query_cap_name()+" strikes you deftly.", obz[i]);
     obz[i]->do_damage(dmg);
     }

   tp->set_disable();
   return 1;
}

int abil() {
    if(!this_player()->is_monster()) 		return 1;
    if(this_player()->query_level() < 2) 	return 0;
    if(this_player()->query_class()=="fighter") return 1;
}

void help() {
   write("Syntax: <whirl [(living)]>\n\n"
  "Fighters are able to use their great skill in combat\n"
  "to whirl between enemies, potentialy doing widespread\n"
  "damage.");
}
