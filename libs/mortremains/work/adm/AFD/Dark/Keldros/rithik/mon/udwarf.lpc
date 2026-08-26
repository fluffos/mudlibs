
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Unliving dwarf");
  enable_commands();
  set("long", @ENDLONG
At first glance, the dwarf seems quite normal, wearing a simply colored
tunic and having the walk of someone who is alive.  However, his eyes are 
colored a deep black, with no whites showing.  Nothing of this plane would 
have such dull, corpse-like eyes.
ENDLONG
  );
  set_alignment(80);
  set_name("unliving dwarf");
  set("id", ({
    "dwarf",
    "unliving dwarf",
  }));
  
  credit(10 + random(100));
  set("damage", ({ 18, 25 }) );
  set("armor_class", 4);

  wear(ARMOR(shield), "shield");
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "medium-build");  set("attrib2", "unliving");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "attempt to crush",
    "bash at",
}));
  set_verbs2( ({
    "attempts to crush",
    "bashes at",
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(6);
  set("chat_chance", 3);
set("chat_output", ({
    "The unlving dwarf warns you: \"You have no idea what lies in the forbidden
fortress, please don't join me\".\n",
    "The dwarf let's out a gentle moan.\n",
  }) );
  set("forgetful", 1);
  
}
