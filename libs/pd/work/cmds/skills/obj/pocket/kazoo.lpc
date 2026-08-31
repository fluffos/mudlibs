
#include <std.h>

#define KAZOO_BONUS_TIME 180
#define KAZOO_USE_TIME KAZOO_BONUS_TIME+200

inherit OBJECT;

mapping BONUSES = ([
  "wanderer" : ({ "entertainer", "entertainment", "euphony" }),
  "rogue" : ({ "prowler", "stealth", "agility" }),
  "fighter" : ({ "defender", "defense", "double wielding" }),
  "mage" : ({ "enchanter", "magic defense", "conjuring" }),
  "clergy" : ({ "priest", "faith", "healing" }),
  "dragon" : ({ "predator", "claw", "tail" }),
  "vampire" : ({ "blood sucker", "ferocity", "melee" }),
  "child" : ({ "misfit", "attack", "defense" }),
]);

int play_me(string);

int used_at;

void create() {
  ::create();
  set_name("kazoo");
  set_property("no store", 1);
  set_id( ({ "little kazoo" }) );
  set_short("a little kazoo");
  set_long("A small metal instrument that makes a buzzing noise when played.");
  set_weight(1);
  set_curr_value("gold", 0);
  used_at = 0;
}

void init() {
  ::init();
  add_action("play_me", "play");
}

int play_me(string str) {
  object tp = this_player();
  object env = environment(tp);
  string *bonus;

  if (!str || present(str, tp) != this_object())
    return 0;

  if (tp->query_sp() < 10)
    return notify_fail("You're too tired to play the kazoo.\n");

  tp->add_sp(-(5+random(6)));

  message("info", "You play a little buzzing tune on the kazoo.", tp);
  message("info", tp->query_cap_name()+" plays a buzzing tune on a kazoo.",
      env, tp);

  if (used_at+KAZOO_USE_TIME > time())
    message("info", "Nothing special happens.", tp);
  else {
    bonus = BONUSES[tp->query_class()];
    message("info", "You feel like a better "+bonus[0]+"!", tp);
    foreach (string sk in bonus[1..<1])
      if (!tp->query_skill_bonus(sk))
        tp->add_skill_bonus(sk, 20-(5*member_array(sk, bonus))+random(15), KAZOO_BONUS_TIME);
  }

  used_at = time();

  return 1;
}

