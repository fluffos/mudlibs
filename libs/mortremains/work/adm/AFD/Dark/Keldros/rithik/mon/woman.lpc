#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A portly woman");
  enable_commands();
  set("long", @ENDLONG
Beldra is a very fat dwarf.  She is wearing an appron which, like her 
face, is covered in burkhberry pie filling.  She is holding a clean pie 
plate, but strangely has no silverware.
ENDLONG
  );
  set_alignment(-100);
  set_name("beldra");
  set("id", ({
    "woman",
    "beldra",
    }));
  
  credit(50 + random(150));
  set("damage", ({ 12, 30}) );
  set("armor_class", 5);
  set_level(5);
  arm(WEAPONS(plate), "plate");
  set("max_hp", 100);
  set("hit_points", 100);
  set("attack_strength",9);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "obese");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "clobber",
    "smack",
}));
  
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 7, "strength");

  set("chat_chance", 6);
  set("chat_output", ({
"The woman licks an empty pie plate to verify she has\ndevoured the entire pie.\n",
"Beldra says: \"I don't understand why people use utensils, your hands\nwork so much
better!\"\n",
"The portly woman shifts her sitting position and nearly falls\noff her chair.\n",   
  }) );
  set("forgetful", 1);
  
}
