#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Resting Halfling");
  enable_commands();
  set("long", @ENDLONG
Delsey is quite short with a plump belly.  He has a child-like face, with a
broad smile
ENDLONG
  );
  set_alignment(100);
  set_name("delsey");
  set("id", ({
    "halfling",
    "delsey",
    "resting halfling",
  }));
  
  credit(random(200) );
  set("damage", ({ 5, 25 }) );
  set("armor_class", 3);

  wear(OBJ(bpack), "backpack");
clone_object(OBJ(torch))->move(TO);
  set("attack_strength", 12);
  set("race", "halfling");
  set("attrib1", "short");  set("attrib2", "plump");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
    "Delsey says: 'Boy that circus was fun!'\n",
    "Delsey's stomach growls loudly.\n",
  }) );
  set("forgetful", 1);
  
}
