#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_lifewarp(string str) {
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
    if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (tp->query_skill("belief") < 150)
      return notify_fail("Your faith is not yet strong enough.\n");
   if (tp->query_skill("healing") < 150)
     return notify_fail("Your powers of healing are not yet strong enough.\n");
   if (tp->query_subclass() != "cleric")
      return notify_fail("What?\n");
   if (tp->query_level() < 35)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
     return notify_fail("This spell does not affect ghosts.\n");
   if (ob == tp)
      return notify_fail("Don't we wish that was possible.\n");
   if (tp->query_mp() < 95) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("healing") + tp->query_skill("wisdom");
   dmg += tp->query_skill("belief");
   dmg -= ob->query_skill("magic defense")/2 + ob->query_skill("wisdom")*2/3;
   dmg -= ob->query_stats("constitution")*2/3;
   dmg *= 3/2;
   if (dmg < 10) {
      write("Your spell fails!");
      tell_room(env, ""+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
  tell_room(env, "%^ORANGE%^"+tp->query_cap_name()+" mutters some words of faith.", ({ tp }));
   write("%^ORANGE%^You mutter some words of faith towards "+ob->query_cap_name()+".");
tell_room(env, "%^RED%^"+ob->query_cap_name()+" cringes in pain as "+tp->query_cap_name()+" has temporarily reversed the flow of blood!", ({ ob, tp }));
  tell_object(ob, "%^RED%^"+ob->query_cap_name()+"'s spell causes you great internal damage!");
  write("%^RED%^Your attack has wrought havoc on "+ob->query_cap_name()+"'s body!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()));
   tp->set_disable(); 
return 1;
}
void help() {
write("
Syntax: <lifewarp [living target]>
A painful attack used by some clerics of high faith and healing, lifewarp reverses the flow of blood within the targets body for a short period of time.  The blood then releases painful impurities throughout the body.
");
}
int spell() {
   object o;
   o = this_player();
   if (o)
   if (o->query_subclass() == "cleric")
     if (o->query_skill("belief") >= 150 && o->query_level() >= 35)
      return 1;
}
