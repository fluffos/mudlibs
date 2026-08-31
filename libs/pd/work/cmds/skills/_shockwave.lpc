//      _tremble.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() {
  write("Syntax: <shockwave [(living)]>\n"
   "Throws a wave of energy at the target "
   "causing minor damage.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 8) return 0;
  return 1;
}
string type() { return "attack"; }
int cmd_shockwave(string str) {
  object tp, ob;
  int i, which, skip, attack;
  object *inv;
  string what;

  if (!spell()) {
    return 0;
  }

  tp = this_player();

  if(tp->query_ghost()) {
    notify_fail("You emit a ghostly moan.\n");
    return 0;
  }

  if (tp->query_busy())
    return notify_fail("You are too busy to cast this spell.\n");

  if(environment(tp)->query_property("no magic")
   || environment(tp)->query_property("no attack")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }

  if((int)tp->query_mp() < 15) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Throw the wave at whom?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("You look silly.\n");
    return 0;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  if(ob->query_property("no magic")) {
    notify_fail(sprintf("%s is immune to such magic.\n",
      ob->query_cap_name()));
    return 0;
  }
  attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "magic attack", "wizardry" }),
   ({ "intelligence" }) );

  attack = attack * 1.25;

  if(attack < 1) attack = 1;
  if(attack > 300) attack = 300 + tp->query_level();

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^BLACK%^%^BOLD%^You throw a %^RESET%^w%^BLACK%^%^BOLD%^a%^RESET%^v%^BLACK%^%^BOLD%^e of %^YELLOW%^energy%^RESET%^%^BLACK%^%^BOLD%^ at " 
   +ob->query_cap_name()+"!%^RESET%^");

  message("room","%^BLACK%^%^BOLD%^"+tp->query_cap_name()+ " throws a %^RESET%^w%^BLACK%^%^BOLD%^a%^RESET%^v%^BLACK%^%^BOLD%^e of %^YELLOW%^energy%^RESET%^%^BLACK%^%^BOLD%^ at "
   +ob->query_cap_name()+"!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^BLACK%^%^BOLD%^"+tp->query_cap_name()+ " throws a %^RESET%^w%^BLACK%^%^BOLD%^a%^RESET%^v%^BLACK%^%^BOLD%^e of %^YELLOW%^energy%^RESET%^%^BLACK%^%^BOLD%^ at you!%^RESET%^",ob);

  ob->do_damage("target", attack, DAMAGE_MAGIC | DAMAGE_IMPACT, 0, tp);

  tp->add_skill_points("magic attack", attack/20 + 2);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));

  tp->set_magic_round();

  return 1;
}
