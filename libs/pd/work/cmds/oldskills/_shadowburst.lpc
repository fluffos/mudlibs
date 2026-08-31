#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_shadowburst(string str) {
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
   if (tp->query_subclass() != "kataan" && tp->query_subclass() != "necromancer")
      return notify_fail("What?\n");
   if (tp->query_level() < 8)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <shadowburst [living]>\n");
   if (ob == tp)
      return notify_fail("The demons laugh at you.\n");
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (tp->query_mp() < 45)
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_stats("wisdom") + tp->query_skill("magic attack")/3;
 if (this_player()->query_subclass()=="kataan")
   dmg += tp->query_skill("faith");
 if (this_player()->query_subclass()=="necromancer")  
   dmg += tp->query_skill("necromancy");
   dmg -= ob->query_stats("wisdom")/2 + ob->query_skill("magic defense")/3;
   dmg *= 3/2;
   if (dmg < 10) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" sends a burst "
     "of shadows at "+ob->query_cap_name()+"!", ({ tp, ob }));
   write("%^BOLD%^%^BLACK%^Shadows engulf "+ob->query_cap_name()+"!");
   tell_object(ob, "%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" sends a "
      "burst of shadows at you!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <shadowburst [living]>
Shadowburst is a kataan and necromancer attack spell. By means of
this spell, the caster engulfs their enemy in harmful shadows.
");
}
int spell() {
   object o;
   o = this_player();
   if (this_player()->query_subclass()!="kataan" &&
       this_player()->query_subclass()!="necromancer") return 0;
   if (o && o->query_level() >= 8)
     return 1;
}
