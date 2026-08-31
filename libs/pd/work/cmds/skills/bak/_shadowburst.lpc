#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_shadowburst(string str) {
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
   if (tp->query_level() < 8)
      return notify_fail("You cannot cast this.\n");
   if (env->query_property("no attack") || env->query_property("no magic"))
      return notify_fail("Greater powers prevent your malice.\n");
   if (tp->query_ghost())
      return notify_fail("Your voice is hollow.\n");
   if (!living(ob))
      return notify_fail("Syntax: <shadowburst [living]>\n");
   if (ob == tp)
      return notify_fail("The demons laugh at you.\n");
   if (this_player()->query_disable() || this_player()->query_casting() || this_player()->query_magic_round())
      return notify_fail("You are busy.\n");
   if (tp->query_mp() < 45)
      return notify_fail("Your spell fails, due to lack of magic.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   dmg = BALANCE3_D->get_damage( tp, ob, 2, ({"magic attack" }),
                                   ({ "intelligence", "wisdom" }) );
   if (dmg < 10) {
      write("Your spell fails.");
      tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
      return 1;
   }
   tell_room(env, "%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" sends a burst "
     "of shadows at "+ob->query_cap_name()+"!", ({ tp, ob }));
   write("%^BOLD%^%^BLACK%^Shadows engulf "+ob->query_cap_name()+"!");
   tell_object(ob, "%^BOLD%^%^BLACK%^"+tp->query_cap_name()+" sends a "
      "burst of shadows at you!");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg);
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <shadowburst [living]>
By means of this spell, the caster engulfs his enemy in harmful shadows.
");
}
int spell() {
   object o;
   o = this_player();
   if (this_player()->query_subclass()!="kataan" &&
       this_player()->query_subclass() != "antipaladin" &&
       this_player()->query_subclass()!="necromancer") return 0;
   if (o && o->query_level() >= 8)
    if (o->query_skill("magic attack") >= 40)
     return 1;
}
