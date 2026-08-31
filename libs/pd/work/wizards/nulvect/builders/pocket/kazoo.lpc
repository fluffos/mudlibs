
#include <std.h>

#define KAZOO_TIME 180

inherit OBJECT;

int play_me(string);

int used_at;

void create() {
  ::create();
  set_name("kazoo");
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

  if (!str || present(str, tp) != this_object())
    return 0;

  if (tp->query_sp() < 10)
    return notify_fail("You're too tired to play the kazoo.\n");

  tp->add_sp(-(5+random(6)));

  message("info", "You play a little buzzing tune on the kazoo.", tp);
  message("info", tp->query_cap_name()+" plays a buzzing tune on a kazoo.",
      env, tp);

  if (used_at+KAZOO_TIME > time())
    message("info", "Nothing special happens.", tp);
  else {
    message("info", "You feel like a better entertainer!", tp);
    tp->add_skill_bonus("euphony", 30+random(10), KAZOO_TIME);
    tp->add_skill_bonus("entertainment", 20+random(10), KAZOO_TIME);
  }

  used_at = time();

  return 1;
}

