#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_torment(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if(!spell()) return 0;
   if (!ob) {
      notify_fail("You do not see that here.\n");
      return 0;
   }
   if (tp->query_subclass() != "kataan")
      return notify_fail("What?\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <torment [living]>\n");
   if (ob == tp)
      return notify_fail("The demons laugh at you.\n");
   if (tp->query_ghost())
      return notify_fail("Your voice is hollow\n");
   if (tp->query_mp() < 25) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
   if (this_player()->query_busy())
      return notify_fail("You are busy.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = BALANCE3_D->get_damage( tp, ob, 1, ({ "faith" }),
                                   ({ "wisdom" }) );
  dmg = dmg*0.7;
  if (dmg > 200) dmg=200+random(tp->query_level()+10);
   if (dmg < 1) {
      write("%^BOLD%^Your spell fails.");
      tell_room(env, "%^BOLD%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^ORANGE%^"+tp->query_cap_name()+" torments "
      +ob->query_cap_name()+"!", ({ ob, tp }));
   tell_object(ob, "%^ORANGE%^"+tp->query_cap_name()+" torments you!");
   write("%^ORANGE%^You torment "+ob->query_cap_name()+"!");
   tp->add_mp(-(BALANCE3_D->get_cost(dmg, 1, "mp")));
   ob->do_damage(0, dmg, DAMAGE_FAITH | DAMAGE_UNHOLY, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);
   tp->add_skill_points("faith", random(tp->query_level()+10));
   tp->set_magic_round();
   return 1;
}
void help() {
write("
Syntax: <torment [living]>
With this spell, Kataan may <torment> their opponents.
");
}
int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 1) return 0;
   if (o && o->query_subclass() == "kataan")
     return 1;
}
