#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
int x;
x = random(3);
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

switch(x)

{
      case 0: wear(ARMOR(l_cloak), "cloak"); break;
      case 1: wear(ARMOR(c_ring), "ring"); break;
      case 2: wear(ARMOR(l_gloves), "gloves"); break;
      case 3: wear(ARMOR(l_pants), "pants"); break;
    default: wear(ARMOR(l_pants), "pants"); break;
}
  set("attrib1", "giant");  set("attrib2", "green");
  set("gender", "neuter");
  set("weapon_name", "webbed hands");
  set_verbs( ({
    "bash at",
    "club at",
}));
  set_verbs2( ({
    "bashes",
    "clubs at",
  
}));
  set_level(random(4));

  
}
