#include <std.h>
#include <daemons.h>
inherit DAEMON;

int abil();
void finish_him(object *stuff);

string type() { return "attack"; }

int cmd_swoop(string str) {
   object ob, tp, env, *blah;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!abil())
      return 0;

   if (tp->query_class() != "dragon")
      return 0;

   if (!ob) {
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }

   if (tp->query_level() < 12)
      return notify_fail("You cannot do that yet.\n");

   if (tp->query_ghost())
      return notify_fail("You swoop through them.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <swoop [living]>\n");

   if (tp->query_disable() || tp->query_casting())
      return notify_fail("You are busy.\n");

   if (ob == tp)
      return notify_fail("You run around in circles.\n");

   if (tp->query_sp() < 50) 
      return notify_fail("You are too tired.\n");

   tp->set_disable();
   tp->set_magic_round(2);
   write("You circle your opponent, preparing to swoop down on them!");
   blah = ({ tp , ob });
   call_out("finish_him", 3, blah);
   call_out("disabler", 1, this_player());
   return 1;
}

void disabler(object tp) {
  tp->set_disable();
}

void finish_him(object *stuff) {
   object ob, tp;
   int dmg;

   tp = stuff[0];
   ob = stuff[1];

   if(!ob)
     return;

   if(environment(ob) != environment(tp)) {
     write("Your prey has evaded you!");
     return;
   }

   tp->set_disable();

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
    return;
    }

   dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "attack", "flying", "flying" "flying", "claw" }),
                                   ({ "dexterity" }) );
   dmg = dmg + dmg*2/3;
   if (dmg < 10) {
      write("You miss!");
      return;
   }
   message("info","You swoop down upon "+ob->query_cap_name()+" and rip "
      +ob->query_objective()+" to pieces!", tp);
   tell_object(ob, tp->query_cap_name()+" swoops down upon you, tearing at you with "
      +possessive(tp)+" claws!");
   message("info", tp->query_cap_name()+" swoops down upon "+ob->query_cap_name()+
      ", tearing "+ob->query_objective()+" to pieces!",environment(tp),({ ob, tp }));
   tp->add_sp(- dmg/7);
   ob->damage(dmg);
    this_player()->add_skill_points("flying", dmg/20);
   return;
}

void help() {
write("
Syntax: <swoop [victim]>\n
Experienced dragons are able to fly around their prey until they see
an opening, then swoop towards them with thier claws extended, causing
extreme damage to thier foe.
");
}

int abil() {
   object o;
   o = this_player();
   if (o && o->query_level() >= 12)
   if (o->query_class() == "dragon")
     return 1;
}
