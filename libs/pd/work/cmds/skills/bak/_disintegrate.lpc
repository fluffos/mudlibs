#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

string type() { return "attack"; }

int cmd_disintegrate(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if(!spell()) return 0;

   if (!ob) {
    if (str)
      notify_fail("You do not see "+str+" here.\n");
      return 0;
   }
   if (tp->query_subclass() != "sorceror" && tp->query_subclass() != "wizard")
      return notify_fail("What?\n");

   if (this_player()->query_busy())
      return notify_fail("You are busy.\n");

   if (tp->query_ghost())
      return notify_fail("You cannot summon your power without a body.\n");

   if (tp->query_skill("psionics") < 60)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <disintegrate [living]>\n");

   if (ob == tp)
      return notify_fail("Attack yourself?\n");

   if (tp->query_mp() < 75) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = BALANCE_D->get_damage( tp, ob, 2, ({ "psionics" }),
                                   ({ "wisdom" }) );
   if (dmg < 10) {
      write("%^CYAN%^Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^B_BLUE%^%^YELLOW%^"+tp->query_cap_name()+
     " attempts to disintegrate "+ob->query_cap_name()+"!%^RESET%^",
     ({ ob, tp }));
   write("%^BOLD%^%^B_BLUE%^%^YELLOW%^You attempt to disintegrate "
     +ob->query_cap_name()+"!%^RESET%^");
   tell_object(ob, "%^BOLD%^%^B_BLUE%^%^YELLOW%^"+tp->query_cap_name()+
     " attempts to disintegrate you!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg);
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <disintegrate [living]>
The caster of this spell attempts to disintegrate their opponent.
");
}

int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 12) return 0;
   if (o && o->query_subclass() == "sorceror" ||
       o->query_subclass() == "wizard")
   if (o->query_skill("psionics") >= 60)
     return 1;
}


