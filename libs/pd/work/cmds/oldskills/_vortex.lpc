#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_vortex(string str) {
   int dmg, i, x;
   object *ob, tp, env;
   tp = this_player();
   env = environment(tp);
   ob = all_inventory(env);
if (tp->query_subclass() != "kataan") {
notify_fail("What?\n");
      return 0;
   }
if (tp->query_level() < 50) {
      notify_fail("You cannot cast this.\n");
      return 0;
   }
   if (env->query_property("no attack") || env->query_property("no magic")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
    if (this_player()->query_disable())
        return notify_fail("You are busy doing something else.\n");
if (tp->query_mp() < 65) {
      return notify_fail("Your magic powers are exhausted.\n");
   }
write("%^BOLD%^MAGENTA%^A sphere of protection envelops you as a vortex forms!%^RESET%^");
tp->set_paralyzed(1, "%^RESET%^BLUE%^The shields energy holds you still.%^RESET%^");
message("info", "%^BOLD%^MAGENTA%^A sphere of protection envelops "
+tp->query_cap_name()+" as a vortex begins to form!%^RESET%^", environment(tp), ({ tp }));
   x=0;
   for (i=1;i-1 < sizeof(ob);i++) {
if (tp->query_mp() < 65)
return notify_fail("Your magic powers are exhausted.\n");
if (ob[i-1]->is_living() && ob[i-1] != tp && !wizardp(ob[i-1]) &&
          ob[i-1]->query_level() >= 3) {
         x = 1;
    if(!this_player()->kill_ob(ob[i-1])) {
        write(ob[i-1]->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
dmg = tp->query_skill("faith")/3 + tp->query_skill("summoning")/3 + tp->query_stats("wisdom") * 2;
dmg += tp->query_skill("magic attack")/3;
dmg -= (ob[i-1]->query_skill("magic defense")/3);
dmg -= (ob[i-1]->query_stats("wisdom"));
dmg += random(this_player()->query_level());
ob[i-1]->damage((dmg*3/2)-(ob[i-1]->query_level()), "magic");
tell_room(env, "%^MAGENTA%^The vortex catches "+ob[i-1]->query_cap_name()+
" and devours its lifeforce!%^RESET%^", ({ ob[i-1] }));
tell_object(ob[i-1], "%^MAGENTA%^The vortex weakens you as it devours your lifeforce!%^RESET%^");
tp->add_mp(-dmg/7);
tp->add_skill_points("faith", dmg/30);
      }
}
   tp->set_magic_round(1);
   tp->set_disable(1);
   return 1;
}
void help() {
write("
Syntax: <vortex>
One of the kataan's most powerful spells, the vortex
attacks the lifeforce of all living beings in the area
excluding the caster.
");
}
int spell() {
   object o;
   o = this_player();
if (o && o->query_subclass() == "kataan" && o->query_level() >= 50)
     return 1;
}
