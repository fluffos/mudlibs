#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Slave-Driving Ant");
  enable_commands();
  set("long", @ENDLONG
This ant is very large, you estimate it is at least six feet tall.  He has 
sharp spinesthe portrude from his shoulders and elbows.  By his general
appearance you sense a degree of evil within him.
ENDLONG
  );
  set_alignment(-50);
  set_name("Slave driver");
  set("id", ({
    "slaver",
    "ant",
    "driver",
     "slave-driver",
  }));
  arm(WEAPONS(whip), "whip");
  credit(60 );
  set("damage", ({ 3, 10 }) );
  set("armor_class", 5);

  set("aggressive", 1);
  set("attack_strength", 12);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "slaver's whip");
  set_verbs( ({
    "trie to lacerate",
    "crack at",
}));
  
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 2, "strength");
  set_level(2);
  set("chat_chance", 1);
  set("chat_output", ({
    "The slave driver cracks his whip angrily .\n",
   
  }) );
  set("forgetful", 1);
  
}
