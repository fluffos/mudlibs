#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_sandstorm(string str) {
   int dmg, i, x;
   object *ob, tp, env;
   tp = this_player();
   env = environment(tp);
   ob = all_inventory(env);
   if(!spell()) return 0;
   if (tp->query_class() != "mage" || tp->query_subclass() != "wizard") {
      notify_fail("What?\n");
      return 0;
   }
   if (tp->query_level() < 20) {
      notify_fail("You cannot cast this.\n");
      return 0;
   }
   if (env->query_property("no attack") || env->query_property("no magic")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
    if(this_player()->query_ghost()) {
        write("You howl pitifully.\n");
        say("You hear a pitiful howl.\n");
        return 1;
    }
   if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
   if (tp->query_mp() < 30) {
      return notify_fail("Your magic powers are exhausted.\n");
   }
   write("At your command, a mighty sandstorm rages!");
   if (!archp(tp))
   tp->set_paralyzed(2+random(3), "The force of the storm holds you back.");
   message("info", "A mighty sandstorm rages at the command of "+tp->query_cap_name()+"!", environment(tp), ({ tp }));
   x=0;
   for (i=1;i-1 < sizeof(ob);i++) {
      if (tp->query_mp() < 30)
         return notify_fail("Your magic powers are exhausted.\n");
      if (ob[i-1]->is_living() && ob[i-1] != tp && !wizardp(ob[i-1]) &&
          ob[i-1]->query_level() >= 3) {
         x = 1;

        if(!this_player()->kill_ob(ob[i-1])) {
           write(ob[i-1]->query_cap_name()+" can't be attacked by you yet.");
            continue;
        }
      
         dmg = BALANCE_D->get_damage( tp, ob[i-1], 2, ({ "magic attack", "conjuring" }),
                                   ({ "wisdom" }) );
         dmg = dmg - dmg/3;
         if(dmg < 0) dmg = 0;
         ob[i-1]->damage(dmg);
         tell_room(env, "Mighty sands whip against "+ob[i-1]->query_cap_name()+
           "'s body!", ({ ob[i-1] }));
         tell_object(ob[i-1], "Mighty sands whip across your body!");
         tp->add_mp(-(ob[i-1]->query_level() + dmg/10));
         tp->add_skill_points("magic attack", dmg/30);
      }
   }
   tp->set_disable();
   return 1;
}
void help() {
write("
Syntax: <sandstorm>
This mighty wizard attack spell brings a tornado of sand upon the
caster's enemys.
");
}
int spell() {
   object o;
   o = this_player();
if(o->query_subclass() == "wizard") return 0;
   if (o && o->query_subclass() == "wizard" && o->query_level() >= 20)
     return 1;
}
