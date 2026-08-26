
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A hungry, tree-eyed human");
  set("long", @ENDLONG
This human looks quite hungry, you can by tell by the look in his three eyes.
ENDLONG
  );
  set_alignment(100);
  set_name("sperk");
  set("id", ({
    "human",
    "sperk",
    "hungry human",
  }));
  
  credit(100 + random(300) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 3);
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "hungry");  set("attrib2", "tired");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat ",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
      "You hear a loud stomach growling that resembles the howling of a hundred demons
set free.\n",
  }) );
  set("forgetful", 1);
  
}
