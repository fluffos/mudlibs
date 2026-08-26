#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Igor the town's executioner");
  enable_commands();
  set("long", @ENDLONG
This dwarf is dressed in dark black, he wears a black
hood that covers his face, showing only his cold, black
eyes .
ENDLONG
  );
  set_alignment(-40);
  set_name("igor");
  set("id", ({
    "igor",
    "executioner",
    }));
  
  credit(random(30)+40);
  set("damage", ({ 5, 35}) );
  set("armor_class", 6);
  set("size", 4);
  wear(ARMOR(hood), "hood");
  set("attack_strength",9);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "stocky");
  set("gender", "male");
  set("weapon_name", "executioner's axe");
  set_verbs( ({
    "slash at",
    "chop at",
    "swing at",
}));
set_verbs2( ({
    "slashes at",
    "chops at",
    "swings at",
}));
  
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 7, "strength");
  set_level(7);
  set("chat_chance", 1);
  set("chat_output", ({
    "Igor stares at the crucified elf and smiles approvingly.\n",
    "Igor says: \"Crucifiction isn't as fun as beheading, I really should talk to 
the mayor.\"\n",
    "Igor looks up at the dead elf and chuckles to himself.\n",   
  }) );
  
}
