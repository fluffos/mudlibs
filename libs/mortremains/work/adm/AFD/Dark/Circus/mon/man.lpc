
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Man dressed in black");
  enable_commands();
  set("long", @ENDLONG
This is a gaunt human, tall with long, dark features.
ENDLONG
  );
  set_alignment(100);
  set_name("the man in black");
  set("id", ({
    "man",
    "man in black",
  }));
  
  credit(200 + random(600) );
  set("damage", ({ 25, 60 }) );
  set("armor_class", 5);

  
  set("attack_strength", 16);
  set("race", "human");
  set("attrib1", "stern");  set("attrib2", "gaunt");
  set("gender", "male");
  set("weapon_name", "black cane");
  set_verbs( ({
    "wallop ",
    "bang",
}));
  set_skill("defense", 10, "dexterity");
  set_skill("attack", 10, "strength");
  set_level(12);
 
  set("forgetful", 1);
  
}
