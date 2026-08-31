#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_lash(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
    if (str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_subclass() != "druid")
      return notify_fail("What?\n");

   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

   if (tp->query_skill("nature") < 70)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <lash [living]>\n");

   if (ob == tp)
      return notify_fail("Attack yourself?\n");

   if (tp->query_mp() < 55) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("nature") + tp->query_stats("wisdom");
   dmg -= ob->query_skill("magic defense")/2 + ob->query_stats("wisdom")/2;
   dmg *= 3/2;
   if (dmg < 10) {
      write("%^CYAN%^Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^GREEN%^Long whip-like vines spring forth from "
     +tp->query_cap_name()+" and lash "+ob->query_cap_name()+"!", ({ ob, tp}));
   write("%^GREEN%^Long whip-like vines spring forth from your hands and "
     "lash "+ob->query_cap_name()+"!");
   tell_object(ob, "%^GREEN%^Long whip-like vines spring forth from "
     +ob->query_cap_name()+" and lash against you.");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->add_skill_points("nature", (dmg/20));
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <lash [victim]>
Lash sends long vines to whip the caster's opponents.
");
}

int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 14) return 0;
   if (o && o->query_subclass() == "druid" &&
       o->query_skill("nature") >= 70)
     return 1;
}

