
#include <std.h>
#include <id4.h>

inherit MONSTER;

void create() {
  int hp;
  ::create();
  set_name("ogre");
  set_short("a big ogre");
  set_long("Even bigger than most ogres, this one has huge muscles "
    "all over his body. His rags barely cover his body.");
  set_gender("male");
  set_race("ogre");
  set_body_type("human");
  set_alignment(-600);
  set_class("fighter");
  set_subclass("berserker");
  set_spells( ({ "headbutt", "pummel", "rush", "brawn" }) );
  set_spell_chance(40);
  set_swarm(1);
  set_level(37+random(4));
  hp=query_max_hp();
  set_stats("strength", 70);
  set_stats("constitution", 70);
  set_stats("intelligence", 5);
  set_stats("wisdom", 5);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
}
