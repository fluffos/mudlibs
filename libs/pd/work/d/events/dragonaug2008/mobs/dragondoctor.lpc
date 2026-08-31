
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("dragon doctor");
  set_id( ({ "dragon", "blue dragon" }) );
  set_short("an old blue dragon");
  set_long(
    "He is extremely girthy and his scales are a light blue. "
    "This dragon spends his time healing others.\n"
    "He can <mend> your wounds for a fee."
  );
  set_gender("male");
  set_level(73);
  set_race("dragon");
  set_body_type("dragon");
  set_class("dragon");
  set_subclass("blue");
  set_alignment(1000);
  set_spells( ({ "iceblast", "dragonfury", "spire", "cure me", "crystallize me" }) );
  set_spell_chance(35);
}

void init() {
  add_action("do_mend", "mend");
}

int do_mend(string str) {
  object tp = this_player();
  string cap = tp->query_cap_name();
  int price, hp;
  hp = tp->query_max_hp() - tp->query_hp();
  if (hp > 300) hp = 300 + (hp-300)/5;
  if (sizeof(query_attackers()) || hp < 0)
    command("emote swishes his tail impatiently.");
  else if (hp < tp->query_max_hp()/12)
    command("say You do not need healing, "+cap+".");
  else if (tp->query_money("platinum") < (price = hp/25))
    command("say That costs "+price+" platinum coins, "+cap+".");
  else {
    command("emote mutters a spell of healing.");
    tp->add_money("platinum", -price);
    tp->add_hp(hp+random(hp/11));
  }
  return 1;
}
