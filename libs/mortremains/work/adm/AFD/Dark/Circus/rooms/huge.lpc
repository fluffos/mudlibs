#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A huge badger");
  enable_commands();
  set("long", @ENDLONG
This is a giant badger, approximately seven feet tall and 4 foot wide at
the shoulders.  he has large claws that
ENDLONG
  );
  set_alignment(100);
  set_name("badger");
  set("id", ({
    "badger",
    "animal",
    "huge badger",
  }));
  set("agressive", 1);
  set("damage", ({ 15, 40 }) );
  set("armor_class", 6);
  set("attack_strength", 14);
  set("race", "badger");
  set("attrib1", "HUGE");  set("attrib2", "long-haired");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "swipe at ",
    "clobber at",
    "slash at",
}));
  set_verbs2( ({
    "swipes at",
    "clobbers at",
    "slashes at",
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7);
  set("forgetful", 1);
  
}
