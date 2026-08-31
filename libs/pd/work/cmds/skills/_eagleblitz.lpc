//      _eagleblitz.c
//      Druid ability
//      written by Daboura, based on pillar

#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;

int spell();
string type() { return "attack"; }
int cmd_eagleblitz(string str) {
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

  if (environment(tp)->query_property("indoors"))
    return notify_fail("You must be outdoors to call down an eagle!");

  if((int)tp->query_mp() < 30) {
    notify_fail("Too low on magic power.\n");
    return 0;
  }

  if (str) ob = present(str, environment(tp));
  else ob = tp->query_current_attacker();

  if (!ob) return notify_fail("Call an eagle down on whom?");

  if(!living(ob)) {
    notify_fail(ob->query_cap_name()+" is not a living thing!\n");
    return 0;
  }

  if(ob==tp) {
    notify_fail("An eagle circles above.\n");
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
  attack = BALANCE3_D->get_damage( tp, ob, 2, ({ "magic attack", "nature", "nature" }),
   ({ "wisdom", "wisdom", "intelligence" }), ({"nature", "conjuring"}) );

  attack = attack*90/100;

  if(attack < 1) attack = 1;

  if(!this_player()->kill_ob(ob)) {
    write(ob->query_cap_name()+" can't be attacked by you yet.");
    return 1;
  }

  write("%^GREEN%^You look toward the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^GREEN%^, and call down an %^ORANGE%^e%^RESET%^a%^ORANGE%^g%^RESET%^l%^ORANGE%^e%^RESET%^%^GREEN%^ to attack "
   +ob->query_cap_name()+ ", an %^BOLD%^%^RED%^enemy%^RESET%^%^GREEN%^ of %^BOLD%^nature%^RESET%^%^GREEN%^!");

  message("target", "%^GREEN%^" +tp->query_cap_name()+
   " looks up at the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^GREEN%^, when suddenly a large %^ORANGE%^e%^RESET%^a%^ORANGE%^g%^RESET%^l%^ORANGE%^e%^RESET%^%^GREEN%^ flys down from the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^GREEN%^ and %^BOLD%^%^RED%^claws%^RESET%^%^GREEN%^ at you!"
   , ob);

  message("room", "%^GREEN%^" +tp->query_cap_name()+
   " looks toward the %^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^%^GREEN%^, then suddenly an %^ORANGE%^e%^RESET%^a%^ORANGE%^g%^RESET%^l%^ORANGE%^e%^RESET%^%^GREEN%^ comes flying down from the heavens and %^BOLD%^%^RED%^claws%^RESET%^%^GREEN%^ at "
   +ob->query_cap_name()+ "!"
   , environment(tp), ({tp,ob}));

  tp->add_skill_points("magic attack", attack/20 + 2);
  tp->add_skill_points("nature", attack/20 + 2);    
  tp->add_skill_points("conjuring", attack/20 + 1);

  tp->add_mp(-BALANCE3_D->get_cost(attack, 2, "mp"));

  tp->set_magic_round();

  ob->do_damage("random", attack, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);

  return 1;
}
void help() {
  write("Syntax: <eagleblitz [(living)]>\n"
   "A more powerful druid can call down an eagle "
   "from the sky to attack the enemy of nature.\n");
}
int spell() {
  object tp;
  tp = this_player();
  if (!tp) return 0;
  if (tp->query_subclass() != "druid") return 0;
  if (tp->query_skill("nature") < 120) return 0;


  return 1;
}

