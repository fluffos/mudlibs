#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a dog");
  enable_commands();
  set("long", @ENDLONG
This is a dog.
ENDLONG
  );
  set_name("dog");
  set("id", ({
    "dog",
		"animal"
  }));
  
  
  set("damage", ({ 2, 5 }) );
  set("armor_class", 1);


  set("attack_strength", 1);
  set("race", "canine");
  set("attrib1", "medium sized");  set("attrib2", "brown");
  set("gender", "male");
  set("weapon_name", "teeth");
  set_verbs( ({
    "gnash at",
    "bite",
  
}));
  set_verbs2( ({
    "gnashes at",
    "bites",
  
}));
  set_skill("defense", 1, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(1);
		set("chat_chance", 3);
   set("chat_output", ({
		"The dog barks noisily at you.\n",
		"The dog growls menancingly at you.\n",
		"The dog licks himself happily.\n",
		

  }) );
  set("forgetful", 1);
  
}
