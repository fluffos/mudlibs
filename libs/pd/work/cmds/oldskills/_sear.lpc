// 5:51 PM 9/4/00 balanced dungeonware.net
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_sear(string str) {
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
   if (tp->query_class() != "mage" || tp->query_subclass() != "pyromancer")
      return notify_fail("What?\n");
   if (tp->query_casting())
      return notify_fail("You are concentrating on something else.\n");
   if (tp->query_level() < 36)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (!living(ob))
      return notify_fail("Syntax: <sear [living]>\n");
   if (ob == tp)
      return notify_fail("Sear yourself?\n");
   if (tp->query_mp() < 250) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("pyromancy") + tp->query_stats("wisdom");
   dmg += tp->query_skill("magic attack")/2;
   dmg -= ob->query_skill("magic defense")/2 + ob->query_stats("wisdom");
   dmg *= 3/2;
   if (dmg < 1) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^RED%^"+tp->query_cap_name()+" sears "
      +ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
   write("%^RED%^You sear "+ob->query_cap_name()+"!%^RESET%^");
   tell_object(ob, "%^RED%^"+tp->query_cap_name()+" sears you!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->set_magic_round();
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <sear [victim]>
This pyromancer attack spell was named after it's purpose; it sears
the pyromancer's opponent.
See also: burn, scald
");
}
int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "pyromancer" && o->query_level() >= 36)
     return 1;
}
