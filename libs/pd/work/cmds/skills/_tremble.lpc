//      _tremble.c
//      Mage ability
//      written by Daboura, based on missile

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

void help() {
  write("Syntax: <tremble [(living)]>\n"
   "Casts a weak energy field around the target causing their "
   "muscles to spasm violently.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "wizard") return 0;
  if (tp->query_level() < 3) return 0;
  return 1;
}
string type() { return "attack"; }
int cmd_tremble(string str) {
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

  if((int)tp->query_mp() < 10) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Make who tremble?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("You shiver.\n");
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

  attack = attack * 1.1;

  if(attack < 10) attack = 15 +random(5);
  if(attack > 250) attack = 250 + tp->query_level();

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^ORANGE%^You flick your wrist and cause " +ob->query_cap_name()+" to tremble %^RED%^%^BOLD%^violently!%^RESET%^");

  message("room","%^ORANGE%^"+tp->query_cap_name()+ " flicks "+tp->query_possessive()+ " wrist and causes "
   +ob->query_cap_name()+" to tremble %^RED%^BOLD%^violently!%^RESET%^", environment(tp), ({tp,ob}));            

  message("ob", "%^ORANGE%^"+tp->query_cap_name()+ " flicks "
   +tp->query_possessive()+ " wrist and causes you to tremble %^RED%^%^BOLD%^violently!%^RESET%^",ob);

  ob->do_damage("target", attack, DAMAGE_MAGIC, DAMAGE_NO_SEVER, tp);

  tp->add_skill_points("magic attack", attack/20 + 2);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 1, "mp"));

  tp->set_magic_round();

  return 1;
}
