#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_envelop(string str) {
   int dmg;
   object ob, tp, env;
   tp = this_player();
   env = environment(tp);
   if(!spell()) return 0;
   if (!str) ob = tp->query_current_attacker();
   else ob = present(str, env);
   if (!ob) {
      notify_fail("You do not see that here.\n");
      return 0;
   }
   if (tp->query_subclass() != "cleric")
      return notify_fail("What?\n");
   if (tp->query_ghost()) return notify_fail("You howl pitifully.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (!living(ob))
      return notify_fail("Syntax: <envelop [living]>\n");
   if (!alignment_ok(tp))
      return notify_fail("You have abandoned the powers of good, thus they abandon you.\n");
   if (ob == tp)
      return notify_fail("The gods laugh at you.\n");
   if (tp->query_mp() < 25) 
      return notify_fail("Your spell fails, due to lack of magic.\n");
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = BALANCE_D->get_damage( tp, ob, 1, ({ "belief" }),
                                   ({ "wisdom" }) );
   if (dmg < 10) {
      write("%^CYAN%^Your spell fails.");
      tell_room(env, "%^CYAN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^WHITE%^An almost-blinding light envelops "
      +tp->query_cap_name()+"'s opponent!", ({ ob, tp }));
   tell_object(ob, "%^BOLD%^%^WHITE%^A blinding light envelops you!");
   write("%^BOLD%^%^WHITE%^A blinding light envelops you!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg);
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <envelop [living]>
This spell is used by those clerics of light beliefs. This spell 
envelops the caster's enemy in a blinding holy light, damaging them.
");
}
int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 2) return 0;
   if (o && o->query_subclass() == "cleric")
     return 1;
}
