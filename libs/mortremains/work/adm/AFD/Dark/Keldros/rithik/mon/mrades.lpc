#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "friendly teacher");
  enable_commands();
  set("long", @ENDLONG
Mr. Ades is a middle-aged dwarf.  He has a friendly face that seems to care about
nothing but being happy.
ENDLONG
  );
  set_alignment(500);
  set_name("Mr. Ades");
  set("id", ({
    "teacher",
    "ades",

  }));
  
  credit(300);
  set("damage", ({ 5, 12 }) );
  set("armor_class", 4);

  set("attack_strength", 13);
  set("race", "dwarf");
  set("attrib1", "middle-aged");  set("attrib2", "bald");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
   set_verbs2( ({
    "punches",
    "tap",
}));

  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 1);
  set("chat_output", ({
    "Mr. Ades says: \"Painting is an artform, we learn it by doing, use your skill 
to better your talent.\"\n",
  }) );
  set("forgetful", 1);
}
