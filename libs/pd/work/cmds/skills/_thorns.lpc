//      _thorns.c
//      Mage ability
//      Written 131092 by Descartes of Borg
//      Remade by Daboura into _thorns.c

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell();
string type() { return "attack"; }
int cmd_thorns(string str) {
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

  if((int)tp->query_mp() < 9) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Throw thorns at whom?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("Throw thorns at yourself?\n");
    return 0;
  }
  if(ob->is_player() && !interactive(ob)) {
    notify_fail("You cannot attack link-dead players.\n");
    return 0;
  }
  if(ob->query_property("no missile")) {
    notify_fail(sprintf("%s is immune to such magic.\n",
      ob->query_cap_name()));
    return 0;
  }

  if(environment(tp)->query_property("no magic")
   || environment(tp)->query_property("no attack")) {
    notify_fail("Something seems to be blocking your concentration.\n");
    return 0;
  }
  attack = BALANCE3_D->get_damage( tp, ob, 1, ({ "nature", "magic attack" }),
   ({ "wisdom" }) );

  attack = attack*60/100;

  if(attack < 10) attack = 10+random(5);
  if(attack > 120) attack = 120 + tp->query_level();
  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^GREEN%^You create a few dozen floating %^BOLD%^thorns%^RESET%^%^GREEN%^ and throw them at " +ob->query_cap_name()+"!%^RESET%^");

  message("room","%^GREEN%^"+tp->query_cap_name()+" seems to create some %^BOLD%^thorns%^RESET%^%^GREEN%^ around "+tp->query_objective()+
   "self, then throws them at "
   +ob->query_cap_name()+"!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^GREEN%^"+tp->query_cap_name()+ " seems to create some %^BOLD%^thorns%^RESET%^%^GREEN%^ around "
   +tp->query_objective()+
   "self, and then throws them at you!%^RESET%^",ob);

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("nature", attack/20 + 2);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));

  tp->set_magic_round();

  ob->do_damage("target", attack, DAMAGE_PHYSICAL | DAMAGE_PIERCE, DAMAGE_NO_SEVER, tp);

  return 1;
}
void help() {
  write("Syntax: <thorns [(living)]>\n"
   "A druid can create a clump of small thorns and throw them "
   "at their target causing minor damage.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if(tp->query_subclass() != "druid") return 0;


  return 1;
}
