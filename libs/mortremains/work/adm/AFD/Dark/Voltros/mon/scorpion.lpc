#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "giant scorpion");
  enable_commands();
  set("long", @ENDLONG
This is a large, black scorpion.
ENDLONG
  );
  set_alignment(0);
  set_name("giant scorpion");
  set("id", ({
    "scorpion",
  }));
  credit(1150);
  set("damage", ({ 27, 67 }) );
  set("armor_class", 13);
  set("hit_points", 240);
  set("attack_strength", 15);
        set ("gender", "female");
        set ("killer", 1);
  set("race", "arachnid");
        set ("pursuing", 1);
  set("attrib1", "large");  set("attrib2", "black");
  set("weapon_name", "pincers", "stinger");
  set_verbs( ({
    "attempt to clamp",
    "lunge at",
    "strike at",
}));
  set_skill("defense", 16, "dexterity");
  set_skill("attack", 16, "strength");
  set_level(15);

}