#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Resting Ant");
  enable_commands();
  set("long", @ENDLONG
This giant ant has slumped shoulders and appears, by your standards, a very tired look.  it has two large that mandibles that portrude from its mouth that appear to be very blunt from what you would imagine.  He appears that whatever he has done lately has made him very tired.
ENDLONG
  );
  set_name("resting ant");
  set("id", ({
    "tired_ant",
    "falling ant",
    "ant",
  }));
  
  credit(32 );
  set("damage", ({ 1, 8 }) );
  set("armor_class", 7);

  wear(OBJ(tidbit), "food");
  set("attack_strength", 9);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "dull mandibles");
  set_verbs( ({
    "chomp at",
    "poke at",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 3, "strength");
  set_level(2);
  
  
  set("forgetful", 1);
  
}
