#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a lean acrobat");
  set("long", @ENDLONG
This acrobat is clothed in a skin-tight body suit.
Her breasts fit nicely into any garmet, however.
ENDLONG
  );
  set_alignment(7);
  set_name("acrobat");
  set("id", ({
    "acrobat",
    "lean acrobat",
  }));

  set("damage", ({ 10, 30 }) );
  set("armor_class", 3);
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "lean");  set("attrib2", "buxom");
  set("gender", "female");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat ",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
  set("chat_output", ({
      "The acrobat bounces into a backflip.\n",
      "The acrobat winks at you and demonstrates teh abillity to place her ankles
on the back of her neck.\n",
  }) );
  set("forgetful", 1);
  
}
