
#include <std.h>
#include <id4.h>

inherit MONSTER;

void create() {
  int hp;
  ::create();
  set_name("ogre");
  set_short("an ogre");
  set_long("This ogre is big and hairy. His thick grey skin is "
    "covered in patches of dirt.");
  set_gender("male");
  set_race("ogre");
  set_body_type("human");
  set_alignment(-600);
  set_class("fighter");
  set_subclass("berserker");
  set_spells( ({ "headbutt", "bash" }) );
  set_spell_chance(40);
  if (random(100) > 50) set_swarm(1);
  if (random(100) < 20) {
    set_moving(1);
	set_speed(20);
  }
  set_level(30+random(3));
  hp=query_max_hp();
  set_stats("strength", 50);
  set_stats("constitution", 50);
  set_stats("intelligence", 5);
  set_stats("wisdom", 5);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
  new(ITEMS+"club")->move(this_object());
  command("wield club");
}
