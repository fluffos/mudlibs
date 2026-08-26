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
    "guard_1",
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
		arm(WEAPONS(kris_dagger),"dagger");
  set("race", "undead");
  set("attrib2", "strong");  set("attrib1", "scowling");
  set("weapon_name", "dagger");
  set_verbs( ({
    "swipe at",
}));
  set_level(10);

}
