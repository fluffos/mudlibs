#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_scald(string str) {
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

   if (tp->query_level() < 6)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <scald [living]>\n");

   if (this_player()->query_disable() || this_player()->query_casting())
      return notify_fail("You are busy.\n");

   if (ob == tp)
      return notify_fail("Scald yourself?\n");

   if (tp->query_mp() < 50) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

   dmg = tp->query_skill("magic attack")/2 + tp->query_stats("wisdom")/2;
   dmg -= ob->query_skill("magic defense")/3 + ob->query_stats("wisdom")/3;
   dmg += random(tp->query_level()/2);
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if (dmg < 1) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^RED%^"+tp->query_cap_name()+" scalds "
      +ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
   write("%^RED%^You scald "+ob->query_cap_name()+"'s skin!%^RESET%^");
   tell_object(ob, "%^RED%^"+tp->query_cap_name()+" scalds your skin!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->set_disable();
   tp->set_casting(dmg);
   tp->set_magic_round();
   ob->damage(dmg, "fire");
   return 1;
}

void help() {
write("
Syntax: <scald [victim]>
Scald is a pyromancer attack spell, which scalds their victim's skin.
See also: burn, mage
");
}

int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "pyromancer" && o->query_level() >= 6)
     return 1;
}

