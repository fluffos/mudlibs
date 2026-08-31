#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_lifetap(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
    if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if (!ob) {
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_disable())
      return notify_fail("You are busy.");
   if (tp->query_skill("belief") < 95)
      return notify_fail("Your faith is not yet strong enough.\n");
   if (tp->query_skill("healing") < 70)
      return notify_fail("Your powers of healing are not yet strong enough.\n");
   if (tp->query_subclass() != "cleric")
      return notify_fail("What?\n");
   if (tp->query_level() < 23)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
     return notify_fail("Syntax: <Lifetap may only be cast upon the living.\n");
   if (ob == tp)
      return notify_fail("Don't we wish that was possible.\n");
   if (tp->query_mp() < 95) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
   if(!this_player()->kill_ob(ob)) {
       write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("healing")/2 + tp->query_skill("wisdom")/2;
   dmg += tp->query_skill("belief");
   dmg -= ob->query_skill("magic defense")/2 + ob->query_skill("wisdom")/2;
   if (dmg < 10) {
      write("%^GREEN%^Your spell fails!");
      tell_room(env, "%^GREEN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^GREEN%^"+tp->query_cap_name()+" attacks "+ob->query_cap_name()+" with a trailing green cord of lifeforce!%^RESET%^", ({ tp }));
   write("%^BOLD%^%^GREEN%^You send a trailing green cord of lifeforce energy towards "+ob->query_cap_name()+".%^RESET%^");
   tell_room(env, "%^GREEN%^"+ob->query_cap_name()+" weakens noticably as "+tp->query_cap_name()+"'s lifetap invades within!%^RESET%^", ({ ob, tp }));
   tell_object(ob, "%^GREEN%^"+ob->query_cap_name()+"'s lifetap invades your lifeforce with their own!");
   write("%^GREEN%^Your lifetap flows within "+ob->query_cap_name()+", causing their lifeforce great damage!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->add_hp(random(ob->query_level()));
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <lifetap [living target]>
One of the clerics most powerful forms of offense, the caster of
lifetap sends a flowing whip of their lifeforce towards a
victim in an attempt to attack the life energies of that opponent.
See also: cleric
");
}
int spell() {
   object o;
   o = this_player();
   if (o)
   if (o->query_subclass() == "cleric")
     if (o->query_skill("belief") >= 95 && o->query_level() >= 23)
      return 1;
}
