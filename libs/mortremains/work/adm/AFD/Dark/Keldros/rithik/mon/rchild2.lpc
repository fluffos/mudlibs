#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "snot-nosed kid");
  enable_commands();
  set("long", @ENDLONG
This kid is straining his eyes reading his book.
ENDLONG
  );
  set_alignment(50);
  set_name("greg");
  set("id", ({
    "kid_2",
    "kid",
    "student",
    "greg",
     
    
    
  }));
  
  credit(5);
  set("damage", ({ 1, 6 }) );
  set("armor_class", 0);
  set_level(1);
  clone_object(OBJ(text3.c))->move(TO);
  set("max_hp", 30);
  set("hit_points", 30);
  set("attack_strength", 2);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "brown-haired");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
   set_verbs2( ({
    "punches",
    "tap",
}));

  set_skill("defense", 0, "dexterity");
  set_skill("attack", 0, "strength"); 
  set("forgetful", 1);
  
}
