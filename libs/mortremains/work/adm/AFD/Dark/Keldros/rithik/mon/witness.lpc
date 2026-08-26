#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "bored witness");
  enable_commands();
  set("long", @ENDLONG
This dwarves grey eyes look very dull, you get the
impression he would rather be somewhere else.
ENDLONG
  );
  set_alignment(25);
  set_name("witness");
  set("id", ({
    "witness", "bored witness"  
  }));
  set("size", 4);
  credit(random(20)+20);
  set("damage", ({ 7, 17 }) );
  set("armor_class", 5);
  clone_object(OBJ(rbag))->move(TO);
  set("attack_strength", 15);
  set("race", "human");
  set("attrib1", "short");  set("attrib2", "dimpled");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "clobber",
}));
  set_verbs2( ({
    "punches",
    "clobbers",
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(6);
  set("chat_chance", 1);
  set("chat_output", ({
    "The witness yawns.\n",
    "The witness says: \"Is this over yet?\"\n",   
  }) );
}
