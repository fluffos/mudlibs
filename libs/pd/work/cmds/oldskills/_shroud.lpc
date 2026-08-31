#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_shroud(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if (!ob) {
    if (str)
      notify_fail("You do not see that here.\n");
      return 0;
   }
   if (tp->query_class() != "mage" || tp->query_subclass() != "pyromancer")
      return notify_fail("What?\n");
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (tp->query_level() < 50)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <shroud [living]>\n");
   if (tp->query_skill("pyromancy") < 45)
      return notify_fail("Your conjuring is not strong enough.\n");
   if (ob == tp)
      return notify_fail("You want to enshroud yourself in flames?\n");
   if (tp->query_mp() < 85) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = tp->query_skill("magic attack") + tp->query_skill("pyromancy")/2;
   dmg += tp->query_stats("wisdom")*3/2;
   dmg -= ob->query_stats("wisdom");
   dmg -= ob->query_skill("magic defense");
   dmg *= 3/2;
   if (dmg < 20) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^ORANGE%^"+tp->query_cap_name()+" magically creates "
     "a shroud of flame around "+ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
   write("%^ORANGE%^You magically create a shroud of flames around
"+ob->query_cap_name()+"!%^RESET%^");
   tell_object(ob, "%^ORANGE%^"+tp->query_cap_name()+" magically creates "
     "a shroud of flame around you!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/3));
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <shroud [victim]>
This powerful pyromancer attack spell creates a shroud of flame about
the victim's body. The flame burns the victim just before it disapears.
See also: sear, scald
");
}
int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "pyromancer" && o->query_level() >= 50)
     if (o->query_skill("pyromancy") >= 45)
     return 1;
}
