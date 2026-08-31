#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_pain(string str) {
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
   if (tp->query_skill("healing") < 25)
      return notify_fail("Your faith is not strong enough.\n");
   if (tp->query_subclass() != "cleric" && tp->query_subclass() != "monk")
      return notify_fail("What?\n");
   if (tp->query_level() < 4)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <pain [living]>\n");
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (ob == tp)
      return notify_fail("Oooooh the agony! Oh the pain!\n");
   if (tp->query_mp() < 35) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
   if (tp->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("healing")/2 + tp->query_stats("wisdom");
  if (this_player()->query_subclass() == "cleric")
   dmg += tp->query_skill("belief")/2;
  if (this_player()->query_subclass() == "monk")
   dmg += tp->query_skill("faith")/2;
   dmg -= ob->query_skill("magic defense")/3 + ob->query_stats("wisdom")/2;
   if (dmg < 1) {
      write("%^CYAN%^Your spell fails.");
      tell_room(env, "%^CYAN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^YELLOW%^"+tp->query_cap_name()+" causes pain in "
      +ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
   write("%^YELLOW%^You cause pain in "+ob->query_cap_name()+"!%^RESET%^");
   tell_object(ob, "%^YELLOW%^"+tp->query_cap_name()+" motions "
      +tp->query_title_gender()+" hand at you, and pain floods your body!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
  if (this_player()->query_subclass() == "monk")  
    tp->add_skill_points("faith", dmg/50);
  if (this_player()->query_subclass() == "cleric")  
    tp->add_skill_points("belief", dmg/50);
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <pain [victim]>
This spell is used by clerics and monks of strong faith to induce a
sudden pain in their victim.
See also: wound
");
}
int spell() {
   object o;
   o = this_player();
   if (o)
   if (o->query_level() < 4) return 0;
    if (o->query_subclass() == "cleric" || o->query_subclass() == "monk")
     if (o->query_skill("healing") >= 20)
      return 1;
}
