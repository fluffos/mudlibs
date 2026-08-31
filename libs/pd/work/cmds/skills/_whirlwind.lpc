//      _whirlwind.c
//      Druid ability
//      written by Daboura, based on pillar

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int spell();
string type() { return "attack"; }
int cmd_whirlwind(string str) {
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

  if((int)tp->query_mp() < 35) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Move the air around whom?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("The air around you swirls.\n");
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
  attack = BALANCE3_D->get_damage( tp, ob, 3, ({ "magic attack", "nature", "nature" }),
   ({ "wisdom", "wisdom", "intelligence" }), ({"nature", "conjuring"}) );

  attack = attack*95/100;

  if(attack < 1) attack = 1;

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^GREEN%^You focus on Mother Nature, and ask her to vanquish the enemies of nature.%^RESET%^");

  message("room", "%^GREEN%^A powerful current of %^RESET%^%^BOLD%^air%^RESET%^%^GREEN%^ forms around "
   +ob->query_cap_name()+
   ", engulfing " +ob->query_objective()+
   " in a huge %^CYAN%^%^BOLD%^w%^RESET%^%^CYAN%^h%^CYAN%^%^BOLD%^i%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^d%^RESET%^%^GREEN%^!"
   , environment(tp), ob);

  message("target", "%^GREEN%^A powerful %^CYAN%^%^BOLD%^w%^RESET%^%^CYAN%^h%^CYAN%^%^BOLD%^i%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^CYAN%^d%^RESET%^%^GREEN%^ surrounds you!", ob);

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("nature", attack/20 + 2);    
  tp->add_skill_points("conjuring", attack/20 + 1);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 3, "mp")*115/100);

  tp->set_magic_round();

  ob->do_damage("all", attack, DAMAGE_FAITH | DAMAGE_AIR, 0, tp);

  return 1;
}
void help() {
  write("Syntax: <whirlwind [(living)]>\n"
   "A stronger druid can call on mother nature to "
   "create a whirlwind around the enemy of nature. "
   "The whirlwind will cause things in the room to "
   "be thrown into the target.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "druid") return 0;
  if (tp->query_skill("nature") < 210) return 0;


  return 1;
}

