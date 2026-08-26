#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "snot-nosed kid");
  enable_commands();
  set("long", @ENDLONG
This student is studying hard.
ENDLONG
  );
  set_alignment(50);
  set_name("Bernice");
  set("id", ({
    "kid_3",
    "kid",
    "student",
    "bernice",
     
    
    
  }));
  
  credit(5);
  set("damage", ({ 1, 6 }) );
  set("armor_class", 0);

  wear(OBJ(text2.c), "book");
  set("hit_points", 30);
  set("attack_strength", 2);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "black-haired");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
  
  set_skill("defense", 0, "dexterity");
  set_skill("attack", 0, "strength");
  set_level(1);
  
    
    
   
  }) );
  set("forgetful", 1);
  
}
