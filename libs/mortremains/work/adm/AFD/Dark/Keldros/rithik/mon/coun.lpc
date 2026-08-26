#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Cordius, the tidy Mayoral Councilor");
  set("long", @ENDLONG
This man is very well kept wearing a neatly pressed black tunic, and 
dark green hose.  His nose is quite long, bolstering small, blue eyes.
ENDLONG
  );
  set_alignment(-20);
  set_name("cordius");
  set("id", ({
    "cordius",
    "councillor"
    
  }));
  
  credit(200+ random(100) );
  clone_object(OBJ(squirt))->move(TO);
  set("damage", ({ 10, 40 }) );
  set("armor_class", 7);
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "neat");  set("attrib2", "long-nosed");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "jump at",
    "jab",
}));
  
  set_skill("defense", 5, "dexterity");
  set_skill("attack", 10, "strength");
  set_level(10);
  set("chat_chance", 3);
  set("chat_output", ({
    "Cordius sprays some water on his beloved plants.\n",
    "Cordius says: \"I wonder how Volskar gets anything done being so messy.\"\n",
    "Cordius looks down his nose at you.\n", 
  }) );
 set("att_chat_output", ({
     "Cordius quirts you in the face!\n",
     "Cordius screams for the town guard.\n", 
}) );
 set("forgetful", 1);
  
}
