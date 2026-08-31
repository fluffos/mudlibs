#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_massacre(string str) {
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
   if (tp->query_race() != "demon")
      return notify_fail("What?\n");
   if (tp->query_level() < 50)
     return notify_fail("Only the elite may use massacre.\n");
   if (this_player()->query_alignment() > -800) {
     notify_fail("You have betrayed your alignment.");
      return 0;
   }
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
     return notify_fail("Syntax: <massacre [living]>\n");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");
   if (ob == tp)
     return notify_fail("You can't massacre yourself.\n");
   if (tp->query_sp() < 250) 
      return notify_fail("You are too tired.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   tp->set_disable();
dmg = tp->query_skill("attack");
dmg += tp->query_skill("melee") * 2/3;
dmg += tp->query_stats("strength") * 5/3;
dmg += tp->query_stats("dexterity")*2;
   dmg -= ob->query_stats("constitution")/3 + ob->query_stats("dexterity")/2;
   dmg -= ob->query_skill("defense")/3;
   dmg *= 2;
   if (dmg < 10) {
      write("You miss!");
      return 1;
   }
   write("%^GREEN%^With blinding speed you unleash several deadly attacks upon "+ob->query_cap_name()+"!");
   tell_object(ob, tp->query_cap_name()+" unleashes several deadly attacks upon you with lightning speed!");
   tell_room(env, tp->query_cap_name()+" unleashes several attacks upon "+ob->query_cap_name()+" with lightning speed!", ({ this_player() }) );
   tp->add_sp(- dmg/7);
   if (ob->query_race()=="archangel" && this_player()->query_alignment()==-1500)
      ob->damage((dmg + random(this_player()->query_level()/2))*3/2);
      else
      ob->damage(dmg + random(this_player()->query_level()/2));
   tp->add_hp(-(dmg/20));
   tp->set_disable(2);
   return 1;
}
void help() {
write("%^RESET%^
Syntax: <massacre [victim]>
One of the most devastating of the demon attacks, massacre involves
using the demon's supernatural strength and dexterity to unleash
several devastating attacks at lightning speed.  This attack is
tremendously taxing and actually injures the demon when used. 
");
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 50)
   if (o->query_race() == "demon") 
     return 1;
}

