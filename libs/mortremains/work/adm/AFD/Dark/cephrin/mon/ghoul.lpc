#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a nasty ghoul");
  set("long", @ENDLONG
The ghoul is what remains of what once was a great warrior.
ENDLONG
  );
  set_alignment(-80);
  set_name("zombie");
  set("id", ({
    "ghoul",
  }));
  wear(ARMOR(r_armor), "armor");
  set("undead", 1);
  credit(800);
  set("damage", ({ 25, 70 }) );
  set("armor_class", 22);
  set_level(17);
	set("aggressive", 1);
  set("hit_points", 400);
  set("attack_strength", 18);
  set("race", "ghoul");
  set("attrib1", "sluggish");  set("attrib2", "man-sized");
  set("weapon_name", "claws");
  set_verbs( ({
    "scratch at",
    "gouge",
}));  
  set_skill("defense", 9, "dexterity");
  set_skill("attack", 9, "strength");

  
}