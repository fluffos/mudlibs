#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "hardened warrior");
  enable_commands();
  set("long", @ENDLONG
This is an elderly gentleman wearing purple robes and and a long hat
showing his rank as Minsteriot in the church of Dryox.
ENDLONG
  );
  set_alignment(100);
  set_name("felsch");
  set("id", ({
    "warrior",
    "hardened warrior",
    "felsch",
    
    
  }));
  
  credit(random(1300) );
  set("damage", ({ 40, 80 }) );
  set("armor_class", 5);

  arm(WEAPONS(jsword), "sword");
  set("attack_strength", 18);
  set("race", "dwarf");
  set("attrib1", "medium built");  set("attrib2", "young");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "lacerate",
    "jab",
    "transfix",

}));
  set_verbs( ({
    "lacerates",
    "jabs",
    "transfixes",

}));
  set_level(28);
  set("chat_chance", 1);
  set("chat_output", ({
    "The warrior pushes you aside as he demands another beer.\n", 
  }) );
  set("forgetful", 1);
  
}
