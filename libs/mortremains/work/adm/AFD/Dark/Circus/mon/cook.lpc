#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A demonic cook");
  set("long", @ENDLONG
This cook is approximately seven feet tall with green flesh covered in
open sores and welts.
ENDLONG
  );
  set_alignment(100);
  set_name("xeqs");
  set("id", ({
    "demon",
    "xeqs",
    "cook",
  }));
  arm(OBJ(pan), "pan");
  credit(100 + random(300) );
  set("damage", ({ 15, 40 }) );
  set("armor_class", 5);
  set("attack_strength", 14);
  set("race", "demon");
  set("attrib1", "beat-up");  set("attrib2", "medium sized");
  set("gender", "male");
  set("weapon_name", "frying pan");
  set_verbs( ({
    "beat",
    "slam at",
}));
  set("no_attack", 1);
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7);
  set("chat_chance", 5);
  set("chat_output", ({
     "The cook stirs the pot some more.\n",
     "The cook says: \"When the stew's done, I'll make up some fried halfing.\"\n", 
}) );
  set("att_chat_output", ({
      "The cook says: 'You will be GREAT in my stew!\n",
}) );
  set("forgetful", 1);
}
