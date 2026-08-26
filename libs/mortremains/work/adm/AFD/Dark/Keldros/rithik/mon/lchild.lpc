#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
::create();
  seteuid(getuid());
  set("short", "snot-nosed kid");
  enable_commands();
  set("long", @ENDLONG
This kid is straining his eyes reading his book.
ENDLONG
  );
  set_alignment(50);
set_name("some kid");
  set("id", ({
    "kid_1",
    "kid",
    "student",
     
    
    
  }));
  
  credit(5);
  set("damage", ({ 1, 6 }) );
  set("armor_class", 0);

wear(OBJ(text3.c), "book");
  set("hit_points", 30);
  set("attack_strength", 2);
  set("race", "dwarf");
set("attrib1", "short"); set("attrib2", "bored");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
  
  set_skill("defense", 0, "dexterity");
  set_skill("attack", 0, "strength");
  set_level(1);
  
    
    
   
 
  set("forgetful", 1);
}
