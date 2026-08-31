#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_sandcone(string str) {
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
   if (tp->query_class() != "clergy" || tp->query_subclass() != "druid") {
      notify_fail("What?\n");
      return 0;
   }
   if (tp->query_level() < 10) {
      notify_fail("You cannot cast this.\n");
      return 0;
   }
   if (env->query_property("no attack") || env->query_property("no magic")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
   if (!living(ob)) {
      notify_fail("Syntax: <sandcone [living]>\n");
      return 0;
   }
   if (ob == tp) {
      notify_fail("Attack yourself?\n");
      return 0;
   }
   if (tp->query_mp() < 60) {
      notify_fail("Your spell fails, due to lack of mp.\n");
      return 0;
   }

   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

   dmg = tp->query_skill("magic attack")/2 + tp->query_stats("wisdom");
dmg += tp->query_stats("intelligence");
   dmg += tp->query_skill("conjuring")/2;
   dmg -= ob->query_skill("magic defense")*2/3 + ob->query_stats("wisdom")/2;
   dmg *= 3/2;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
}
   if (dmg < 10) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, tp->query_cap_name()+" sends a cone of sand flying at "
      +ob->query_cap_name()+"!", ({ ob, tp }));
   write("You send a cone of sand flying at "+ob->query_cap_name()+"!");
   tell_object(ob, tp->query_cap_name()+" sends a cone of sand flying "
      "at you!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <sandcone [living]>
Sandcone is a wizard attack spell that sends a concentrated cone of
sand at their opponent.
");
}

int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "druid" && o->query_level() >= 10)
     return 1;
}

