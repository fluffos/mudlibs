#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "boring teacher");
  set("long", @ENDLONG
Mr. Lyman looks like a kind, strict teacher
ENDLONG
  );
  set_alignment(80);
  set_name("Mr. Lyman");
  set("id", ({
    "teacher",
"lyman",



  }));
  credit(random(200)+100);
  set("damage", ({ 5, 12 }) );
  set("armor_class", 4);
  wear(OBJ(glass), "glasses");
  wear(OBJ(coat), "jacket");
  set("attack_strength", 13);
  set("race", "dwarf");
  set("attrib1", "elderly"); set("attrib2", "wrinkled");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));

  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
"Mr. Lyman cleans his glasses with his sleeve.\n",
"Mr. Lyman says: \"My students are so lazy, but when they work I reward them.\"\n",



  }) );
  set("forgetful", 1);
}