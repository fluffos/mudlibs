#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a beastly animal trainer");
  set("long", @ENDLONG
This thing appears to be humanoid walking upright
with two arms and two legs, but that is where the
'human' leaves the description.  It has a thick
green flesh that is littered with boils and puss
pockets.  Two glowing red eyes peer about suspiciously.
ENDLONG
  );
  set_alignment(-20);
  set_name("beast");
  set("id", ({
    "beast",
    "trainer",
    "animal trainer",
  }));
  
  credit(300 + random(400) );
  set("damage", ({ 20, 60 }) );
  set("armor_class", 3);
  set("attack_strength", 10);
  set("race", "demon");
  set("attrib1", "grotesque");  set("attrib2", "beastly");
  set("gender", "neuter");
  set("weapon_name", "fists");
  set_verbs( ({
    "smack",
    "beat",
    "attack",
}));
  set_skill("defense", 15, "dexterity");
  set_skill("attack", 15, "strength");
  set_level(16);
  
}
