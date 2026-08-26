#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "crochety old man");
  enable_commands();
  set("long", @ENDLONG
This old man is wearing a scanty pair of overalls.
ENDLONG
  );
  set_alignment(500);
  set_name("old man");
  set("id", ({
    "man",
    "old man",
  }));
  
  credit(random(35)+10);
  set("damage", ({ 9, 29 }) );
  set("armor_class", 4);

  
  set("attack_strength", 13);
  set("race", "dwarf");
  set("attrib1", "young");  set("attrib2", "red-haired");
  set("gender", "male");
  set("weapon_name", "oakwood cane");
  set_verbs( ({
    "poke at",
    "swing at",
}));
  
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 25, "strength");
  set_level(7);
  set("chat_chance", 2);
  set("chat_output", ({
    "The old man grumbles something about a cemetary.\n",
    "The Old Man says: \"If you plan on goin' to the cemetary, you should take a torch.\"\n",
    "The Old Man says: \"My wife is buried just north of here.\n",
}) );
  set("forgetful", 1);
  
}
