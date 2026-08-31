
#include <std.h>
#include <saahr.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("satyr");
  set_race("satyr");
  set_body_type("human");
  set_gender("male");
  set_id(({"satyr"}));
  set_short("satyr");
  set_long("This merry looking fellow seems almost to dance rather than walk. "
           "His cheeks are rosy; his mouth always smiling. Like most satyrs, "
           "he looks to be in good shape, though not really muscular. The vest "
           "he wears as his only adornment is open, letting in the breeze.");

  set_class("wanderer");
  set_subclass("gypsy");
  set_level(40);

  set_spells(({"sing sinners psalm","perform dance of the zephyrs",
	       "perform spinning dervish"}));
  set_spell_chance(65);

  set_inventory( ([
    ARM+"satyrvest" : "wear vest",
    WEP+"utilityknife" : "wield knife",
  ]) );

}

