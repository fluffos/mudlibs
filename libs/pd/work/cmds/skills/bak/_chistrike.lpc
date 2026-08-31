#include <std.h>
#include <daemons.h>
#include <rest.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_chistrike(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if(!abil()) return 0;
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if (!ob) {
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (this_player()->query_busy())
      return notify_fail("You are busy.\n");
   if (this_player()->query_ghost())
      return notify_fail("You are unable to summon your chi without your body.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <chistrike [living target]>\n");
   if (ob == tp)
      return notify_fail("You can't Chistrike yourself.\n");
   if (tp->query_mp() < 95) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
//   this_player()->set_magic_round(2);
   if(!this_player()->kill_ob(ob)) {
      write(ob->query_cap_name()+" can't be attacked by you yet.");
      return 1;
    }
   dmg = BALANCE_D->get_damage( this_player(), ob, 3, ({ "faith", "faith", "attack" }),
                                   ({ "wisdom", "intelligence" }), ({ "strength" }) );
   dmg *= 3/2;
   if (dmg < 25) {
      write("%^CYAN%^Your spell fails!");
      return 1;
   }
   tell_room(env, "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" points at "+ob->query_cap_name()+".", ({ tp }));
   write("%^BOLD%^%^WHITE%^You concentrate your chi energy into a physical force and slam it into "+ob->query_cap_name()+"!");
   tell_room(env, "%^YELLOW%^"+tp->query_cap_name()+" launches a force at "+ob->query_cap_name()+"!", ({ ob, tp }));
   tell_object(ob, "%^YELLOW%^A force slams into you, sending you screaming to the ground!!");
   write("%^YELLOW%^The force slams into "+ob->query_cap_name()+" sending "+ob->query_objective()+" sprawling on the ground!");
   tp->add_mp(-(dmg/12));
   tp->add_sp(-(dmg/12));
   tp->set_casting(dmg);
   if (random(100) > 65){
     ob->add_sp(-(dmg/10));
     ob->set_rest_type( SIT );
     if(!ob->is_player()) ob->set_paralyzed(random(2)-1);
   }
//   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <chistrike [living target]>
Concentrating their chi energy into a physical force, 
monks can send their chi out of their body to strike their opponent. 
This is a draining move on both the target and the caster.
");
}
int abil() {
   object o;
   o = this_player();
   if (o)
    if (o->query_subclass() == "monk")
     if (o->query_skill("faith") >= 184 && o->query_level() >= 30)
      return 1;
}
