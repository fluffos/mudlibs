#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "skeletal warrior");
  enable_commands();
  set("long", @ENDLONG
This skeleton's purpose is to patrol the temple and to keep out any intruders.
ENDLONG
);
  set_name("skeletal warrior");
  set("id", ({
    "warrior",
    "skeleton",
  }));
  credit(random(50) + 10 );
  set("damage", ({ 13, 39 }) );
  set("armor_class", 10);
  set("aggressive", 1);
  set("undead", 6);

  arm(WEAPONS(awl-pike), "awl-pike");
  set("attack_strength", 11);
  set("race", "undead");
  set("attrib1", "medium sized");
  set("gender", "neuter");
  set("weapon_name", "awl-pike");
  set_verbs( ({
    "thrust at",
    "lance",
}));
  set_skill("defense", 12, "dexterity");
  set_skill("attack", 10, "strength");
  set_level(random(9) + 6);
  set_alignment(-100);
}
