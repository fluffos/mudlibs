#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "child");
  enable_commands();
  set("long", @ENDLONG
This little girl is playing in the mud.  She looks up at you, but decides that
you are nothing, and begins playing again.
ENDLONG
  );
  set_name("child");
  set("id", ({
    "child",
		"girl",
		"munchkin",
  }));
  
  
  set("damage", ({ 1, 2 }) );
  set("armor_class", 1);
	wear(OBJ(whistle), "green toy whistle");
set("size" , 2);
  set("attack_strength", 1);
  set("race", "munchkin");
  set("attrib1", "tiny");  set("attrib2", "humanoid");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "swings at",
    "punch",
  
}));
  set_verbs2( ({
    "swings at",
    "punches",
  
}));
  set_skill("defense", 1, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(1);

set("chat_chance", 2);
set("chat_output", ({
   "The little girl begins to sing 'It's a Small World' as she makes a mudpie.\n",
  }) );
  set("forgetful", 1);
  
}
