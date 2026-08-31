// a dungeonware.net production -00.07.08-
// coded for Primal Darkness by Stormbringer
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_snapkick(string str) {
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
   if (tp->query_subclass() != "monk")
      return notify_fail("What?\n");
   if (tp->query_level() < 8)
      return notify_fail("You cannot do this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <snapkick [living]>\n");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");
   if (ob == tp)
      return notify_fail("You kick your leg into the air.\n");
   if (tp->query_sp() < 50) 
      return notify_fail("You are too tired.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   tp->set_disable();
   dmg = tp->query_skill("melee") + tp->query_skill("attack")/2;
   dmg += tp->query_stats("strength")*3/4 + tp->query_stats("dexterity")/2;
   dmg -= ob->query_stats("constitution")*3/4 + ob->query_stats("dexterity")/2;
   dmg -= ob->query_skill("defense")/2;
   if (dmg < 10) {
      write("You miss!");
      return 1;
   }
   write("You snapkick "+ob->query_cap_name()+"!");
   tell_object(ob, tp->query_cap_name()+" kicks "
      +tp->query_title_gender()+" foot out and snapkicks you!");
   tell_room(env, tp->query_cap_name()+" snapkicks "+ob->query_cap_name()+
" and slams "+tp->query_title_gender()+" foot into "+ob->query_title_gender()+" face!");
   tp->add_sp(- dmg/7);
   ob->damage(dmg);
   return 1;
}
void help() {
write("
Syntax: <snapkick [victim]>
Monks, followers of melee combat may snapkick their enemys,
slamming their foot into their face.
");
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 8)
   if (o->query_subclass() == "monk")
     return 1;
}
