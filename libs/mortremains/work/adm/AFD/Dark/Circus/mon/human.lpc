#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Resting Human");
  enable_commands();
  set("long", @ENDLONG
Kurn is a rough-looking adventurer.  A five 'o clock shadow outlines his
kind but hard eyes.
ENDLONG
  );
  set_alignment(100);
  set_name("kurn");
  set("id", ({
    "human",
    "kurn",
    "resting human",
  }));
  
  credit(100 + random(300) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 3);

  
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "stern");  set("attrib2", "bearded");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
    "Kurn says: 'I hated that circus, it was so wierd!'\n",
    "Kurn complains about some of his food delsey consumed without his permission.\n",
  }) );
  set("forgetful", 1);
  
}
