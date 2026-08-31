// a dungeonware.net production -00.07.08-
// coded for Primal Darkness by Stormbringer
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_circlekick(string str) {
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
   if (!abil())
      return 0;
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <circlekick [living]>\n");
   if (tp->query_busy())
      return notify_fail("You are busy.\n");
   if (ob == tp)
      return notify_fail("You can't kick yourself.\n");
   if (tp->query_sp() < 50) 
      return notify_fail("You are too tired.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(tp->query_ghost())
      return notify_fail("Your leg goes through them.\n");
   tp->set_disable();
   dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "melee" }),
                                   ({ "strength", "dexterity" }) );
   if (dmg < 10) {
      write("You miss!");
      return 1;
   }
   write("You bring your leg around in a circle striking "+ob->query_cap_name()+" on the side of the face with your foot!");
   tell_object(ob, tp->query_cap_name()+" brings "+tp->query_title_gender()+" leg around in a circle striking you in the side of the face!");
   tell_room(env, tp->query_cap_name()+" circlekicks "+ob->query_cap_name()+" and slams "+tp->query_title_gender()+" foot into "+ob->query_title_gender()+" face!");
   tp->add_sp(- dmg/7);
   ob->damage(dmg);
   return 1;
}
void help() {
write("
Syntax: <circlekick [victim]>
An advanced form of snapkick, monks circlekick their enemys, slamming a foot into their face.
");
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 13)
   if (o->query_subclass() == "monk")
     return 1;
}
