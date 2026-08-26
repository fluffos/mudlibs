#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a black-skinned clown");
  set("long", @ENDLONG
This clown looks like it was once human, but now is covered in 
black makeup.  Red makeup covers huge lips.  He has a demented 
look in his eye.
ENDLONG
  );
  set_alignment(-20);
  set_name("clown");
  set("id", ({
    "clown",
    "warped clown",
  }));
  
  credit(100 + random(300) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 3);
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "hungry");  set("attrib2", "tired");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat ",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
      "The clown makes fun of the demon by mocking his facial expressions.\n",
  }) );
  set("forgetful", 1);
  
}
