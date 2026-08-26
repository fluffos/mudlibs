#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A dwarven game hunter");
  enable_commands();
  set("long", @ENDLONG
Zodrax wears multiple layers of furs that keep him warm.
He maintains a glare that reflects a coldness in his soul.
ENDLONG
  );
  set_alignment(-100);
  set_name("zodrax");
  set("id", ({
    "hunter",
    "zodrax",
    }));
  
  credit(50+random(220));
  set("damage", ({ 20, 38}) );
  set("armor_class", 5);

  arm(WEAPONS(hbow), "bow");
  set("attack_strength",9);
  set("race", "dwarf");
  set("attrib1", "medium-heighth");  set("attrib2", "stocky");
  set("gender", "male");
  set("weapon_name", "bow");
  set_verbs( ({
    "pull back the string on the bow and lets fly at",
    "pierce",
}));

  
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 7, "strength");
  set_level(5);
  set("chat_chance", 6);
  set("chat_output", ({
    "Zodrax complains about how cold it is, and puts another log in the fireplace.",
    "Zodrax says: \"I wonder if Beldra is going to bring a pie over this evening,
I do love her pie so.\"\n",
    "Zodrax admires his trophies and grins evilly.\n",   
  }) );
  set("forgetful", 1);
}
