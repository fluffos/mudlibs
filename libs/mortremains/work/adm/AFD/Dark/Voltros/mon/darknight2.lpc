#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "andrion, the Death Knight");
  enable_commands();
  set("long", @ENDLONG
This is a Death Knight.  It was at one time a good knight at one time
that became perverted by evil.  Now, in death, it has returned to serve
it's master in a deed that it vowed to do even before it's death.  The
knights head is just a skull, with a red glow flowing from the eye sockets.
It wears armor and it's mace is readied for combat.   
ENDLONG
  );
  set_alignment(-80);
  set_name("Andrion, the Death Knight");
  set("id", ({
    "knight_2",
    "knight",
    "death knight",
  }));
  credit(0);
  set("damage", ({ 27, 57 }) );
  set("armor_class", 9);
  set("hit_points", 240);
  set("attack_strength", 10);
  set("gender", "male");
		set("undead", 15);
		wear(ARMOR(deathchain),"chainmail");
		arm(WEAPONS(darkmace),"mace");
  set("race", "undead");
  set("attrib2", "strong");  set("attrib1", "scowling");
  set("weapon_name", "mace");
  set_verbs( ({
    "attempt to bludegon",
}));
  set_level(12);

}
