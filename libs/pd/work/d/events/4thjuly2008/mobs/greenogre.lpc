
#include <std.h>
#include <id4.h>

inherit MONSTER;

void create() {
  int hp;
  ::create();
  set_name("ogre");
  set_short("a green ogre");
  set_long("The skin of this ogre is a dull green. Matted black hair "
    "hangs on all sides of his head.");
  set_gender("male");
  set_race("ogre");
  set_body_type("human");
  set_alignment(-700);
  set_class("fighter");
  set_subclass("antipaladin");
  set_spells( ({ "headbutt", "slash", "whip", "shadowburst" }) );
  set_spell_chance(50);
  set_level(33+random(4));
  hp = query_max_hp();
  set_stats("strength", 50);
  set_stats("constitution", 50);
  set_stats("intelligence", 15);
  set_stats("wisdom", 15);
  set_stats("charisma", 5);
  set_max_hp(hp);
  set_hp(query_max_hp());
  set_mp(query_max_mp());
  new(ITEMS+"sword")->move(this_object());
  new(ITEMS+"whip")->move(this_object());
  command("wield sword");
  command("wield whip");
}
