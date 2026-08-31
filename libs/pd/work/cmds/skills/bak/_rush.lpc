#include <std.h>
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_rush(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if(!abil())
     return 0;
   if (!ob) {
    if (str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_class() != "fighter")
      return notify_fail("What?\n");
   if (tp->query_level() < 12)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <rush [living]>\n");
   if (tp->query_disable())
      return notify_fail("You are busy.\n");
   if (ob == tp)
      return notify_fail("You run around in circles.\n");
   if (tp->query_sp() < 50) 
      return notify_fail("You are too tired.\n");
    if(tp->query_rest_type())
       return notify_fail("You cannot do that while on the ground!\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   tp->set_disable();
      dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "charging", "melee" }),
        ({ "strength", "strength", "dexterity" }) );
   if (dmg < 10) {
      write("You miss!");
      return 1;
   }
   write("You rush at "+ob->query_cap_name()+" and slam your shoulder into "
      +ob->query_objective()+"!");
   tell_object(ob, tp->query_cap_name()+" rushes at you, and slams "
      +tp->query_title_gender()+" shoulder into you!");
   message("combat", tp->query_cap_name()+" rushes at "+ob->query_cap_name()+
     " and slams "+tp->query_title_gender()+" shoulder into "+
       ob->query_objective()+"!", env, ({ tp, ob }));
   tp->add_sp(-(dmg/7));
   ob->damage(dmg);
   return 1;
}
void help() {
write("
Syntax: <rush [victim]>
Any experienced member of the fighter class may rush at their enemies,
slamming their shoulder into them.
");
}
int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 12)
   if (o->query_class() == "fighter")
     return 1;
}
