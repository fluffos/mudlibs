#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a wounded worker ant");
  enable_commands();
  set("long", @ENDLONG
This ant is the largest ant you have ever seen.  When standing full-erect, 
he measures 4' high and weighs perhaps 80 pounds.  Long antennae 
portrude from its forehead that move in a seemingly random pattern.  
Its mouth contains two large mandibles, which appear to be his only tools 
for mining this cavern. This ant appears to have been wounded, for its
head is bandaged.
ENDLONG
  );
  set_name("worker ant");
  set("id", ({
    "worker_ant",
    "ant",
    "worker",
  }));
  arm(WEAPONS(mandible), "mandible");
  wear(ARMOR(bandage), "bandage");
  credit(random(30) + 5 );
  set_level(3);
  set("damage", ({ 5, 16 }) );
  set("armor_class", 3);
  set("race", "ant");
  set("condition_suppress", 1);
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "sharp mandibles");
  set_verbs( ({
    "chomp at",
    "tear at",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
  
  set("chat_chance", 2);
  set("chat_output", ({
    " The wounded ant groans in pain.\n",
  }) );
  set("forgetful", 1);
}
