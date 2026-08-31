#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_thornwrack(string str) {
   int dmg, x;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
    if (str)
      notify_fail("You do not see '"+str+"' here.\n");
      return 0;
   }
   if (tp->query_class() != "mage" || tp->query_subclass() != "druid")
      return notify_fail("Nature does not listen to you.\n");

   if (tp->query_level() < 15)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   
   if (!living(ob))
      return notify_fail("Syntax: <thornwrack [living]>\n");

   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");

   if (tp->query_skill("nature") < 55)
      return notify_fail("Your conjuring is not strong enough.\n");

   if (ob == tp)
      return notify_fail("Not quite your brightest idea yet...\n");

   if (tp->query_mp() < 75)
      return notify_fail("Your spell fails, due to lack of magic.\n");

   tp->kill_ob(ob);
   dmg = tp->query_skill("nature")/2 + tp->query_stats("wisdom")/3;
   dmg -= ob->query_stats("wisdom")/4 + ob->query_skill("defense")/6;
   if (dmg < 1) {
      write("%^BLUE%^Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   x = tp->query_level() - ob->query_level();
   x += tp->query_stats("intelligence");
   x -= ob->query_stats("wisdom");
   x = (x - ob->query_stats("constitution")/2) + tp->query_stats("wisdom");
   x += tp->query_level()/10;
  if (x < 1) return notify_fail("Your spell fails.\n");
//   for (;x > 10;x = x/10) { }
   tell_room(env, tp->query_cap_name()+" screams as "+(string)x+" thorns rip out of "+ob->query_cap_name()+"'s skin.", ({ ob, tp }));
   tell_object(ob, (string)x+" thorns suddenly rip out of your skin, then retract back into it!");
   write((string)x+" thorns rip out of "+ob->query_cap_name()+"'s skin, "
       "then retract back into it!");
   ob->damage(dmg/2*x, "magic");
   tp->add_mp(-(random(70)+(dmg/20)*3) + random(this_player()->query_level()));
   tp->add_skill_points("nature", (10 + random(15)));
   if (x > 6)
     ob->set_disable();
   tp->set_disable();
   return 1;
}

void help() {
write("
This powerful druid spell calls to the nature in all living things and
summons great thorns to attack from the inside out.
");
}

int spell() {
   object o;
   o = this_player();
  if (o && o->query_subclass() == "druid" && o->query_level() >= 15)
     if (o->query_skill("nature") >= 55)
     return 1;
}
