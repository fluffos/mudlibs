
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "skeletal warrior");
  enable_commands();
  set("long", @ENDLONG
This is an undead warrior, animated to kill those who
trounce the battle ground
ENDLONG
  );
  set_alignment(-25);
  set_name("warrior");
  set("id", ({
    "warrior",
    "skeleton",
    "skeletal warrior",
  }));
  
  credit(100 + random(50) );
  set("damage", ({ 25, 55 }) );
  set("armor_class", 3);
  wear(ARMOR(r_armor.c), "armor");
  set("aggressive", 1);
  set("attack_strength", 10);
  set("race", "skeleton");
  set("attrib1", "ancient");  set("attrib2", "dried");
  set("undead", 3);
  set("gender", "neuter");
  set("weapon_name", "rusted sabre");
  set_verbs( ({
    "swing at",
    "slice at",
    "cut",
    "chop at",
}));
  set_skill("defense", 10, "dexterity");
  set_skill("attack", 12, "strength");
  set_level(12);

}
