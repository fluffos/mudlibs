
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
  set_alignment(-600);
  set_class("clergy");
  set_subclass("monk");
  set_spells( ({ "chistrike", "circlekick", "furystrike", "ironskin" }) );
  set_spell_chance(40);
  set_level(39+random(3));
  hp=query_max_hp();
  set_stats("strength", 70);
  set_stats("constitution", 60);
  set_stats("intelligence", 5);
  set_stats("wisdom", 25);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
  set_mp(query_max_mp());
}
