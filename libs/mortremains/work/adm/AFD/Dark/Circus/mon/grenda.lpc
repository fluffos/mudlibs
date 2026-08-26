#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Grenda, the costume maker");
  set("long", @ENDLONG
Grenda is an elderly woman who looks to be enjoying her work.
ENDLONG
  );
  set_alignment(120);
  set_name("grenda");
  set("id", ({
    "grenda",
    "maker",
    "costume maker",
  }));
  credit(10 + random(60) );
  set("damage", ({ 5, 30 }) );
  set("armor_class", 3);
  set("attack_strength", 11);
  set("race", "human");
  set("attrib1", "elderly");  set("attrib2", "kind");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 3, "dexterity");
  set_skill("attack", 3, "strength");
  set_level(5);
  set("chat_chance", 3);
  set("chat_output", ({
    "Grelda whispers something to herself.\n",
    "The woman says: 'That frankie sure does like my work!.\n",
}) );
  set("forgetful", 1);
  
}
