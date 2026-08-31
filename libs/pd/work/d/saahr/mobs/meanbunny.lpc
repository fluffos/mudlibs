
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_property("bite", 1);
  set_name("bunny");
  set_id( ({ "bunny", "mean bunny", "rabbit", "orange bunny" }) );
  set_short("%^RESET%^an %^ORANGE%^orange%^RESET%^ bunny");
  set_long(
    "This little bunny is a brownish-orange color. She lays back her ears "
    "and bares her teeth, ready to fight. Her teeth look a little bit red..."
  );
  set_race("rabbit");
  set_body_type("quadruped");
  set_gender("female");
  set_moving(1);
  set_speed(10+random(10));
  
  set_class("fighter");
  set_subclass("berserker");
  set_level(58+random(3));

  set_stats("strength", 90);
  set_stats("constitution", 250);
  set_max_hp(query_max_hp()*2);
  set_hp(query_max_hp());
  
  set_spell_chance(45);
  set_spells( ({ "bite", "bite", "rush", "rush", "brawn", "fury", }) );
}

