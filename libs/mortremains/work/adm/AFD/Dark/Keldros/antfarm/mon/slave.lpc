#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Slave Ant");
  enable_commands();
  set("long", @ENDLONG
This ant is covered with scrapes and scratches, it moves very slowly and clumsily,
By the way he acts, you believe this ant to be a slave.
ENDLONG
  );
  set_name("slave");
  set("id", ({
    "slave",
    "slave ant",
    "ant",
  }));
  
  
  set("damage", ({ 1, 3 }) );
  set("armor_class", 0);


  set("attack_strength", 1);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "claws");
  set_verbs( ({
    "slash at",
    "throw himself at",
  
}));
  set_verbs2( ({
    "slashes at",
    "lunges at",
  
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(3);

  set("forgetful", 1);
  
}
