#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_darkmist(string str) {
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
   if ((tp->query_subclass() != "kataan") && (tp->query_subclass() != "black"))
      return notify_fail("What?\n");
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <darkmist [living]>\n");
   if (ob == tp)
      return notify_fail("The demons laugh at you.\n");
   if (tp->query_mp() < 25) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(this_player()->query_subclass() == "kataan")
     dmg = tp->query_skill("faith")*2/3 + tp->query_stats("wisdom")*3/2;
   else
     dmg = tp->query_skill("wizardry")*2/3 + tp->query_stats("wisdom")*3/2;
   dmg -= ob->query_stats("wisdom")/2 + ob->query_skill("magic defense")/4;
   if (dmg < 10) {
      write("%^CYAN%^Your spell fails.");
      tell_room(env, "%^CYAN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^BLACK%^A black light, then a crimson mist hits "
      +ob->query_cap_name()+"!", ({ ob, tp }));
   write("%^BOLD%^%^BLACK%^A black light, then a crimson mist "
      "hits "+ob->query_cap_name()+"!");
   tell_object(ob, "%^BOLD%^%^BLACK%^A black light hides you, and a crimson mist "
      "makes you %^RESET%^%^RED%^bleed%^BOLD%^%^BLACK%^!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->add_skill_points("faith", (10 + random(20)));
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <darkmist [living]>
This spell, used by the kataan, sends a light, blacker
than the mists of their faith to hide their opponent. Once in the mists,
a crimson mist decends, and their opponent bleeds!
");
}
int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 2) return 0;
   if(o->query_subclass() == "black") return 1;
   if (o && o->query_subclass() == "kataan")
     return 1;
}
