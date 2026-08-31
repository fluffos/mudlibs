
#include <std.h>
#include <id4.h>

inherit MONSTER;

void create() {
  int hp;
  ::create();
  set_name("ogre");
  set_short("a black ogre");
  set_long("The skin of this ogre is so black that he looks almost "
    "like a demon. His only clothing is a loincloth wrapped about his "
    "midsection.");
  set_gender("male");
  set_race("ogre");
  set_body_type("human");
  set_alignment(-900);
  set_class("rogue");
  set_subclass("thug");
  set_spells( ({ "clobber", "headbutt", "smash", "dirt" }) );
  set_spell_chance(45);
  set_aggressive(40);
  set_swarm(1);
  set_level(36+random(6));
  hp=query_max_hp();
  set_stats("strength", 70);
  set_stats("constitution", 60);
  set_stats("intelligence", 5);
  set_stats("wisdom", 5);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
  set_mp(query_max_mp());
}
