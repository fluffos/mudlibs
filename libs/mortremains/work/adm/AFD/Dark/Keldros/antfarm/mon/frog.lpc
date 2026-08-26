#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a giant frog");
  enable_commands();
  set("long", @ENDLONG
This is a giant, humanoid frog, it appears quite
more intelligent than it's genetic predecessor.
ENDLONG
  );
  set_name("giant frog");
  set("id", ({
    "frog",
    "giant frog",
  }));
  set("damage", ({ 1, 3 }) );
  set("armor_class", 0);
  set("attack_strength", 1);
  set("race", "frog");
  set("attrib1", "giant");  set("attrib2", "green");
  set("gender", "neuter");
  set("weapon_name", "webbed hands");
  set_verbs( ({
    "bash at",
    "club at",
}));
  set("aggressive", 1);
  set_verbs2( ({
    "bashes",
    "clubs at",
  
}));
  set_level(4);

  set("forgetful", 1);
  
}
