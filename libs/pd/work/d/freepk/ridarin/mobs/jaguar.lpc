
#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_id( ({ "jaguar" }) );
  set_name("jaguar");
  set_short("a jaguar");
  set_long(
    "A relatively dark, yellow cat with black spots all over. "
    "It has long claws and a mouth that opens wide enough for it to perform "
    "its signature kill - biting through the top of its prey's skull."
  );
  if (random(2))
    set_gender("male");
  else
    set_gender("female");
  set_level(45+random(2));
  set_race("jaguar");
  // yeah, weird body type, but it has the right limbs
  set_body_type("canine");
  set_emotes(10, ({
    "The jaguar lets out a low hiss.",
    "The jaguar growls and prepares to pounce!",
  }), 1);
  set_aggressive(50+random(11));
  set_class("animal");
  set_subclass("strong");
  set_spell_chance(45);
  set_spells( ({ "bite", "claw" }) );
  set_properties( ([ "bite" : 1, "claw" : 1]) );
}

