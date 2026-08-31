#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_darkmist(string str) {
  int dmg;
  int dtype;
  string skill;
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
  if ((tp->query_subclass() != "kataan") && (tp->query_subclass() != "black"))
    return notify_fail("What?\n");
  if (this_player()->query_disable() || this_player()->query_magic_round() || this_player()->query_casting())
    return notify_fail("You are busy.\n");
  if (env->query_property("no attack") || env->query_property("no magic"))
    return notify_fail("Greater powers prevent your malice.\n");
  if (!living(ob))
    return notify_fail("Syntax: <darkmist [living]>\n");
  if (ob == tp)
    return notify_fail("The demons laugh at you.\n");
  if (tp->query_mp() < 25) 
    return notify_fail("Your spell fails, due to lack of magic.\n");
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  switch (tp->query_subclass()) {
  case "kataan":
    skill = "faith"; dtype = DAMAGE_FAITH | DAMAGE_UNHOLY;
    break;

  case "black":
    skill = "wizardry"; dtype = DAMAGE_MAGIC | DAMAGE_UNHOLY;
    break;
  }
  dmg = BALANCE3_D->get_damage( tp, ob, 1, ({ skill }), ({ "wisdom" }) );
  dmg=dmg*85/100;
  if (dmg > 250) dmg=250+random(tp->query_level()+10);
  if (dmg < 10) {
    write("%^CYAN%^Your spell fails.");
    tell_room(env, "%^CYAN%^"+tp->query_cap_name()+"'s spell fails.", ({ tp }));
    return 1;
  }
  tell_room(env, "%^BOLD%^%^BLACK%^A black light, then a crimson mist hits "
   +ob->query_cap_name()+"!", ({ ob, tp }));
  write("%^BOLD%^%^BLACK%^A black light, then a crimson mist "
   "hits "+ob->query_cap_name()+"!");
  tell_object(ob, "%^BOLD%^%^BLACK%^A black light hides you, and a crimson mist "
   "makes you %^RESET%^%^RED%^bleed%^BOLD%^%^BLACK%^!");
  tp->add_mp(-(BALANCE3_D->get_cost(dmg, 1, "mp")));
  ob->do_damage(0, dmg, dtype, DAMAGE_BYPASS_ARMOUR | DAMAGE_HP_ONLY, tp);
  tp->add_skill_points(skill, 10);
  tp->set_magic_round();
  return 1;
}
void help() {
  write("
Syntax: <darkmist [living]>
This spell, used by the kataan, sends a light, blacker
than the mists of their faith to hide their opponent. Once in the mists,
a crimson mist decends, and their opponent bleeds!
");
}
int spell() {
   object o;
   o = this_player();
   if (o->query_level() < 2) return 0;
   if(o->query_subclass() == "black") return 1;
   if (o && o->query_subclass() == "kataan")
     return 1;
}
