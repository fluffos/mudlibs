#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Worker Ant");
  enable_commands();
  set("long", @ENDLONG
This ant is the largest ant you have ever seen.  When standing full-erect, 
he measures 4' high and weighs perhaps 80 pounds.  Long antennae 
portrude from its forehead that move in a seemingly random pattern.  
Its mouth contains two large mandibles, which appear to be his only tools 
for mining this cavern.
ENDLONG
  );
  set_name("worker ant");
  set("id", ({
    "worker_ant",
    "ant",
    "worker",
  }));
  arm(WEAPONS(mandible), "mandible");
  credit(random(15) + random(15) + 5 );
  set("damage", ({ 3, 10 }) );
  set("armor_class", 2);

  
  set("attack_strength", 12);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "sharp mandibles");
  set_verbs( ({
    "chomp at",
    "tear at",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(2);
  set("chat_chance", 2);
  set("chat_output", ({
    " The worker ant busily hurries to finish his work day, but never seems to catch up.\n
",
   "You see the ant's antennae moving quickly as he attempts to mine the walls for precious copper ore with his mandibles.\n",
  }) );
  set("forgetful", 1);
  set("att_chat_output", ({
    "The worker ant wiggles his antennae wildly in anger.\n",
  }) );
}
