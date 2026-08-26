#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Volskar, the town treasurer");
  set("long", @ENDLONG
This man is wearing casual garb that looks filthy.  He looks like he
hasn't had much sleep lately.
ENDLONG
  );
  set_alignment(-20);
  set_name("volskar");
  set("id", ({
    "volskar",
    "treasurer"
    
  }));
  
  credit(200+ random(500) );
  set("damage", ({ 10, 40 }) );
  set("armor_class", 7);
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "dirty");  set("attrib2", "sweating");
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
    "Volskar searches for something on his desk.\n",
    "The treasurer says: \"I really should make this bank deposit.\"\n",
    "Volskar checks his pockets for something and a look of relief rolls across 
his face.\n", 
  }) );
 set("att_chat_output", ({
     "Volskar slaps you across the face like a woman!\n",
     "The treasurer tells you: \"You will never get the deposit!!!!!\"\n", 
}) );
 set("forgetful", 1);
  
}
