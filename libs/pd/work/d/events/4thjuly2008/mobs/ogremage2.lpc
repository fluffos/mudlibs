
#include <std.h>
#include <id4.h>

inherit MONSTER;

void create() {
  int hp;
  ::create();
  set_name("ogre");
  set_short("an ogre");
  set_long("This ogre is big and hairy. His thick grey skin is "
    "covered in patches of dirt, but his eyes shine with an odd "
    "degree of intelligence.");
  set_gender("male");
  set_race("ogre");
  set_body_type("human");
  set_alignment(-800);
  set_class("mage");
  set_subclass("necromancer");
  set_spells( ({ "plague", "disease", "shadowburst", "siphon" }) );
  set_spell_chance(60);
  set_aggressive(50+random(10));
  set_level(32+random(7));
  hp=query_max_hp();
  set_stats("strength", 30);
  set_stats("constitution", 40);
  set_stats("intelligence", 35);
  set_stats("wisdom", 15);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
  set_mp(query_max_mp());
}
