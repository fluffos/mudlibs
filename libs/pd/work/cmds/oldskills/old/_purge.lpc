#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_purge(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);

   if (!ob) {
      notify_fail("You do not see that here.\n");
      return 0;
   }
   if (tp->query_subclass() != "monk")
      return notify_fail("What?\n");

   if (tp->query_level() < 8)
      return notify_fail("You cannot cast this.\n");

   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");

   if (!living(ob))
      return notify_fail("Syntax: <purge [living]>\n");

   if (ob == tp)
      return notify_fail("The gods laugh at you.\n");

   if (tp->query_mp() < 45) 
      return notify_fail("Your spell fails, due to lack of magic.\n");

    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = (tp->query_alignment() - ob->query_alignment()) / 2;
   dmg += (tp->query_skill("faith") - ob->query_skill("faith"));
   if (dmg < 0) dmg *= -1;
   if (dmg < 10) {
      write("%^CYAN%^Your beliefs are too similar.");
      tell_room(env, "%^CYAN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^ORANGE%^"+tp->query_cap_name()+" purges "
      +tp->query_title_gender()+" opponent!", ({ ob, tp }));
   tell_object(ob, "%^ORANGE%^"+tp->query_cap_name()+" purges you!");
   write("%^ORANGE%^You purge the opponent of your faith.");
   tp->add_mp(-dmg);
   tp->set_magic_round(4);
   tp->set_casting(dmg);
   tp->set_paralyzed(random(3)+1, "You lack the strength to move.");
   return 1;
}

void help() {
write("
Syntax: <purge [living]>
By means of this spell, the monk caster attempts to damage enemies of
their alignment. The more contrast between the caster and the victim's
alignments, the more damage the spell will give.
");
}

int spell() {
   object o;
   o = this_player();
   if (o && o->query_subclass() == "monk" && o->query_level() >= 8)
     return 1;
}
