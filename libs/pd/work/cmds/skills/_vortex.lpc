#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_vortex(string str) {
   int dmg, i, x;
   object *ob, tp, env;
   tp = this_player();
   env = environment(tp);
   ob = all_inventory(env);
   if(!spell()) return 0;

   if (tp->query_level() < 50) {
      notify_fail("You cannot cast this.\n");
      return 0;
   }
   if (env->query_property("no attack") || env->query_property("no magic")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
    if (this_player()->query_busy())
        return notify_fail("You are busy doing something else.\n");
   if (!alignment_ok(tp))
     return notify_fail("Nothing happens.\n");
   if (tp->query_ghost()) return notify_fail("You cannot summon as a ghost.\n");
   if (tp->query_mp() < 65) {
      return notify_fail("Your magic powers are exhausted.\n");
   }
   tp->set_magic_round(1);
   tp->set_disable(1);
   write("%^BOLD%^MAGENTA%^A sphere of protection envelops you as a vortex forms!%^RESET%^");
   tp->set_paralyzed(1, "%^RESET%^BLUE%^The shield's energy holds you still.%^RESET%^");
   message("info", "%^BOLD%^MAGENTA%^A sphere of protection envelops "
               +tp->query_cap_name()+" as a vortex begins to form!%^RESET%^", environment(tp), ({ tp }));
   x=0;
   for (i=1;i-1 < sizeof(ob);i++) {
      if (tp->query_mp() < 65)
         return notify_fail("Your magic powers are exhausted.\n");
      if (ob[i-1]->is_living() && ob[i-1] != tp && strlen(ob[i-1]->query_long()) ) {
         x = 1;
         if(!this_player()->kill_ob(ob[i-1])) {
            write(ob[i-1]->query_cap_name()+" can't be attacked by you yet.");
            continue;
            //return 1;
         }
         dmg = BALANCE3_D->get_damage( tp, ob[i-1], 4, ({ "magic attack", "faith", "summoning" }),
                                   ({ "wisdom" }), ({ "summoning" }) );
         dmg = dmg*5/4;
         ob[i-1]->do_damage(0, dmg, DAMAGE_FAITH | DAMAGE_UNHOLY, DAMAGE_HP_ONLY | DAMAGE_BYPASS_ARMOUR, tp);
         tell_room(env, "%^MAGENTA%^The vortex catches "+ob[i-1]->query_cap_name()+
         " and devours its lifeforce!%^RESET%^", ({ ob[i-1] }));
         tell_object(ob[i-1], "%^MAGENTA%^The vortex weakens you as it devours your lifeforce!%^RESET%^");
         tp->add_mp(-(35+BALANCE3_D->get_cost(dmg, 4, "mp") * 90 / 100));
         tp->add_skill_points("summoning", dmg/40);
      }
   }
   tp->add_alignment(-2);
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
    if (o->query_skill("magic attack") >= 5*50 &&
        o->query_skill("summoning") >= 6*50 &&
        o->query_skill("faith") >= 6*50)
     return 1;
}
