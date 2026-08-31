#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_wound(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
      notify_fail("You do not see that here.\n");
      return 0;
   }
   if (tp->query_subclass() != "cleric")
      return notify_fail("What?\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <wound [living]>\n");

   if (!alignment_ok(tp))
      return notify_fail("You have abandoned your faith.\n");

   if (ob == tp)
      return notify_fail("The gods laugh at you.\n");

   if (tp->query_mp() < 25) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("healing")/2 + tp->query_stats("wisdom")/2;
   dmg -= (ob->query_stats("wisdom")/3 + ob->query_skill("magic defence"))/3;
   if (dmg < 1) {
      write("%^CYAN%^Your spell fails.");
      tell_room(env, "%^CYAN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^YELLOW%^"+tp->query_cap_name()+" wounds "
      +ob->query_cap_name()+"!", ({ ob, tp }));

   tell_object(ob, "%^YELLOW%^"+tp->query_cap_name()+" wounds you!");
   write("%^YELLOW%^You wound "+ob->query_cap_name()+"!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <wound [living]>
With this spell, clerics may <wound> their opponents.
");
}

int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 1) return 0;
   if (o && o->query_subclass() == "cleric")
     return 1;
}


