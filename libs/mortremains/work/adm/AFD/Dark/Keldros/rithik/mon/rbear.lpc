#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "ring bearer");
  enable_commands();
  set("long", @ENDLONG
The ring bearer is wearing a green vest.  He holds
a red pillow with 2 gold rings on it.
ENDLONG
  );
  set_alignment(40);
  set_name("dask");
  set("id", ({
    "ring bearer",
    "dask",
    "boy",
    "bearer",
  }));
  clone_object(OBJ(ring))->move(TO);
  clone_object(OBJ(ring))->move(TO);
  credit(60);
  set("damage", ({ 5, 12 }) );
  set("armor_class", 5);
  set("wimpy", 25);
  set("attack_strength", 12);
  set("race", "dwarf");
  set("attrib1", "young");  set("attrib2", "brown-haired");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
set_verbs2( ({
    "punches",
    "taps",
})); 
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 1);
  set("chat_output", ({
    "The ring bearer waits patiently.\n",   
  }) ); 
}
