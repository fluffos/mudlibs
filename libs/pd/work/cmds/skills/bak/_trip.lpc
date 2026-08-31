// /cmds/skills/_trip.c
// Inferno(06/19/2001);
// stormy hack
 
#include <std.h>
#include <rest.h>
#include <daemons.h>
inherit DAEMON;
int abil();

string type() { return "attack"; }
 
int cmd_trip(string str) {
   int dmg;
   object ob, env, tp;
   if (!abil())
     return notify_fail("What?\n");
   env = environment(this_player());
   tp = this_player();
   if (!str) ob = this_player()->query_current_attacker();
   else ob = present(str, env);
   if (!ob || !ob->is_living())
     return notify_fail("You do not see that here.\n");
   if (ob==this_player())
     return notify_fail("You trip and fall down.\n");
   if(this_player()->query_ghost())
     return notify_fail("Hard to trip without a body..\n");
   if (this_player()->query_busy())
     return notify_fail("You are not oriented enough to do this.\n");
   if (environment(this_player())->query_property("no attack"))
     return notify_fail("Greater powers prevent your malice.\n");
   if ((int)this_player()->query_sp() < 20)
     return notify_fail("You are too tired.\n");
   if (ob->query_rest_type() == SIT)
     return notify_fail(ob->query_cap_name()+" is already on the ground!\n");
   if(!this_player()->kill_ob(ob)) {
      write(ob->query_cap_name()+" can't be attacked by you yet.");
      return 1;
    }
   tp->set_disable();
   dmg = tp->query_stats("dexterity") + 10;
   dmg -= (ob->query_stats("dexterity") / 2) + random(ob->query_stats("dexterity")/2);
   if (dmg < random(25)) {
      write("You spin at "+ob->query_cap_name()+", miss "+possessive(ob)+" and fall to the ground.");
      message("info", tp->query_cap_name()+" spins around on the ground and tries to trip you but misses and falls to the ground.", ob);
      message("info", tp->query_cap_name()+" spins around on the ground and tries to trip "+ob->query_cap_name()+" but misses and falls to the ground.",environment(ob), ({ tp, ob }));
      tp->set_rest_type( SIT );
      ob->damage(dmg+random(dmg));
      tp->add_sp(dmg/5);
      return 1;
   }
   write("You spin around on the ground and trip "+ob->query_cap_name()+", "+ob->query_subjective()+" lands with a thud!");
   message("info", tp->query_cap_name()+" spins around on the ground and trips you, sending you to the ground with a thud!", ob);
   message("info", tp->query_cap_name()+" spins around on the ground and trips "+ob->query_cap_name()+", "+ob->query_subjective()+" lands on the ground with a thud!",environment(ob), ({ tp, ob }));
   ob->set_rest_type( SIT );
   ob->damage(dmg+random(dmg));
   ob->set_paralyzed(random(1),"You are sitting.");
   tp->add_sp(-(dmg/5));
   return 1;
}
void help() {
   write(@ENDTEXT
Syntax: <trip [living]>
This ability is a fairly easy to learn wanderer attack. The wanderer
drops to the ground and spins around, tripping his or her victim.
The living target then falls to the ground, taking damage.
ENDTEXT);
}
int abil() {
   object r;
   r = this_player();
   if (r->query_class() != "wanderer") return 0;
   if (r->query_level() >= 2) return 1;
}
