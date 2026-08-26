#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "undead guard");
  enable_commands();
  set("long", @ENDLONG
This is a undead guard.  It's sole purpose in life, (or unlife),
is to guard a place, person, or thing.  It was created for this 
sole purpose, and it will fight to it's death to make sure that
it follows it's orders.   
ENDLONG
  );
  set_alignment(-40);
  set_name("undead guard");
  set("id", ({
    "guard_2",
    "guard",
    "undead guard",
  }));
  credit(0);
  set("damage", ({ 27, 47 }) );
  set("armor_class", 5);
  set("hit_points", 210);
  set("attack_strength", 9);
  set("gender", "male");
		set("undead", 15);
		arm(WEAPONS(darkmace),"mace");
  set("race", "undead");
  set("attrib2", "strong");  set("attrib1", "scowling");
  set("weapon_name", "dagger");
  set_verbs( ({
    "swipe at",
}));
  set_skill("defense", 11, "dexterity");
  set_skill("attack", 11, "strength");
  set_level(10);

}
