
#include <std.h>
#include <id4.h>

inherit MONSTER;

void create() {
  int hp;
  ::create();
  set_name("ogre");
  set_short("a yellow ogre");
  set_long("The skin of this ogre is a dull yellow. He has almost no hair "
    "at all, but a thick vest covers his body.");
  set_gender("male");
  set_race("ogre");
  set_body_type("human");
  set_alignment(-700);
  set_class("fighter");
  set_subclass("warrior");
  set_spells( ({ "rush", "slash", "warblade", "whirl" }) );
  set_spell_chance(50);
  set_aggressive(50+random(6));
  set_level(38+random(5));
  hp=query_max_hp();
  set_stats("strength", 70);
  set_stats("constitution", 60);
  set_stats("intelligence", 5);
  set_stats("wisdom", 5);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
  set_mp(query_max_mp());
  new(ITEMS+"sword")->move(this_object());
  new(ITEMS+"sword")->move(this_object());
  new(ITEMS+"vest")->move(this_object());
  command("wield sword");
  command("wield sword 2");
  command("wear vest");
}
