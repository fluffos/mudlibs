#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "wounded man");
  enable_commands();
  set("long", @ENDLONG
This human is bleeding profusely from his abdomen.  Claw marks can
be seen all over his body.  His clothes are in disaray.  He looks at you
with a fear in his eyes.
ENDLONG
  );
  set_name("wounded man");
  set("id", ({
                "wounded",
								"man",
                "human",
  }));
  credit(180 );
  set("weapon_name", "hands");
	clone_object("/d/Dark/Voltros/obj/coin")->move(this_object());
  set("damage", ({1, 5 }) );
  set("armor_class", 3);

  set("attack_strength", 2);
  set("race", "human");
  set("attrib1", "medium-sized");  set("attrib2", "brown-haired");
  set("gender", "male");
  set_verbs( ({
    "slap",
    "strike",

}));
  set_verbs2( ({
    "slaps",
    "strikes",

}));
  set_skill("defense", 3, "dexterity");
  set_skill("attack", 3, "strength");
  set_level(2);
  set ("hit_points", 5);
  set ("no_attack", 1);
  set("forgetful", 1);

}