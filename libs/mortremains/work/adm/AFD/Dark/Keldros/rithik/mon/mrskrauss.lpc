#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  set( "aggressive", 1);
  ::create();
  set("short", "cruel teacher");
  enable_commands();
  set("long", @ENDLONG
Mrs. Krauss is middle-aged, with a giant mole resting on her upper lip.
Her eyes are cruel.
ENDLONG
  );
  set_alignment(-500);
  set_name("mrs. Krauss");
  set("id", ({
    "teacher",
    "krauss",
  }));
  credit(200);
  set("damage", ({ 5, 12 }) );
  set("armor_class", 4);
  arm(WEAPONS(ystick), "stick");
  set("attack_strength", 13);
  set("race", "dwarf");
  set("attrib1", "tall");  set("attrib2", "long-haired");
  set("gender", "female");
  set("weapon_name", "yard stick");
  set_verbs( ({
    "thrash",
    "smack",
}));
  set_verbs2( ({
    "thrashes",
    "smacks",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 7);
  set("chat_output", ({
    "Mrs. Krauss yells: \"I am sick of this laziness, work harder!\"\n",
    "Mrs. Krauss clears her throat with a throaty 'haaaaaaaaaggggggggghhhh'\n",
    "The teacher strokes her mole thoughtfully\n",
    "Mrs. Krauss says: \"I am astounded any of you graduated from Kindergarden.\"\n",
    "Mrs. Krauss says: \"You children are so foul.\"\n",
    "The teacer pulls her skirt out of her butt crack and smells her hand.\n",
   
  }) );
  set("forgetful", 1);
}
