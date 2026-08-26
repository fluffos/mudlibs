
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "undead lieutenant");
  enable_commands();
  set("long", @ENDLONG
This undead warrior is a lietenant of a long-dead
army, markings on his nearly destroyed uniform.
ENDLONG
  );
  set_alignment(-25);
  set_name("lieutenant");
  set("id", ({
    "lieutenant",
    "undead lieutenant",
    "skeleton",
  }));

  wear(ARMOR(legs.c), "leggings");
  credit(900 + random(50) );
  set("damage", ({ 38, 70 }) );
  set("armor_class", 3);
  set("aggressive", 1);
  set("attack_strength", 20);
  set("race", "skeleton");
  set("attrib1", "ancient");  set("attrib2", "large");
  set("undead", 3);
  set("gender", "neuter");
  set("weapon_name", "grimy claws");
  set_verbs( ({
    "swing at",
    "swipe at",
    "cut",
}));
  set_skill("defense", 20, "dexterity");
  set_skill("attack", 20, "strength");
  set_level(20);

}
