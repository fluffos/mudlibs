#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "drone ant");
  set("long", @ENDLONG
This is a worker ant whose sole purpose is the
transportation of materials that are used for the
operation of his society.  He is about five feet tall
ENDLONG
  );
  set_name("drone");
  set("id", ({
    "drone",
    "ant",    
  }));

  credit(random(25) + random(25) + 10 );
  set("damage", ({ 3, 8 }) );
  set("armor_class", 5);
  clone_object(OBJ(tidbit))->move(TO);
  set("attack_strength", 12);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "male");
  set("weapon_name", "claws");
  set_verbs( ({
    "tear at",
    "attempt to shred",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(3);
  set("forgetful", 1);
}




