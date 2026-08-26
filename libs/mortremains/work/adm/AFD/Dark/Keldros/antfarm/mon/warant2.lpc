


#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "warrior ant");
  enable_commands();
  set("long", @ENDLONG
This ant lives to fight.  He is a member of a class of ants that defend the colony
from would-be intruders
ENDLONG
  );
  set_name("warrior ant");
  set("id", ({
    "warrior",
    "ant",
    
  }));
  
  credit(random(25) + random(25) + 10 );
  set("damage", ({ 3, 9 }) );
  set("armor_class", 4);
  
  set("aggressive", 1);
  arm(WEAPONS(spear), "spear");
  set("attack_strength", 10);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "brittle spear");
  set_verbs( ({
    "thrust at",
    "attempt to perforate",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 2, "strength");
  set_level(4);
  
  set("forgetful", 1);
  
}

