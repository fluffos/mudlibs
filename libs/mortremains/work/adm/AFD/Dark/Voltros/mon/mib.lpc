#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "man in black");
  enable_commands();
  set("long", @ENDLONG
Kurn is a rough-looking adventurer.  A five 'o clock shadow outlines his
kind but hard eyes.
ENDLONG
  );
  set_alignment(0);
  set_name("test-bunny");
  set("id", ({
    "human",
    "kurn",
    "man",
  }));
  
  credit(100 + random(300) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 5);

  
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "stern");  set("attrib2", "bearded");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 7, "dexterity");
  set_skill("attack", 9, "strength");
  set_level(5);
  set("chat_chance", 4);
}
