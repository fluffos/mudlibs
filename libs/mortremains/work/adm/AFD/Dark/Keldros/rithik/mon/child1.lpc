#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "snot-nosed kid");
  enable_commands();
  set("long", @ENDLONG
This kid looks like trouble on two feet and is covered with paint.
ENDLONG
  );
  set_alignment(-100);
  set_name("Kurt");
  set("id", ({
    "kid_2",
    "kid",
    "student",
    "kurt",
  }));
  
  credit(5);
  set("damage", ({ 1, 6 }) );
  set("armor_class", 0);

  clone_object(OBJ(can2.c))->move(TO);
  set("hit_points", 30);
  set("attack_strength", 2);
  set("race", "dwarf");
  set("attrib1", "short");  set("attrib2", "black-haired");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
 set_verbs2( ({
    "punches",
    "tap",
}));
  
  set_skill("defense", 0, "dexterity");
  set_skill("attack", 0, "strength");
  set_level(1);
  set("chat_chance", 4);
  set("chat_output", ({
    "Kurt cries about his lost lunch money.\n",
  }) );
  set("forgetful", 1);
}
