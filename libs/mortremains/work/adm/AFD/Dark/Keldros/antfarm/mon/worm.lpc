#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "gigantic worm");
  enable_commands();
  set("long", @ENDLONG
This is a giant white worm.  it has a very tough hide and you can see strong
muscles rippling under its flesh.
ENDLONG
  );
  set_name("giant worm");
  set("id", ({
    "worm",
    "gigantic worm",
    
  }));
  
  
  set("damage", ({ 1, 5 }) );
  set("armor_class", 4);


  set("attack_strength", 3);
  set("race", "worm");
  set("attrib1", "gigantic");  set("attrib2", "white");
  set("gender", "male");
  set("weapon_name", "mouth");
  set_verbs( ({
    "attempt to devour",
    "leap at",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 3, "strength");
  set_level(3);
  set("chat_chance", 2);
  set("chat_output", ({
    "You hear an oozing sound as the worm pushes itself through its hole.\n"

   
  }) );
  set("forgetful", 1);
  
}
