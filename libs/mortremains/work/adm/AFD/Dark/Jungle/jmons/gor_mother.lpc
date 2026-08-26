/*
** FILE:    gor_mother.c
** DATE:    20 Aug 1996
** PURPOSE: "Mother Gorilla" - A brown mother gorilla for the jungle area.
**
**
** CHANGES:
**
** 20 Aug 1996    Gambit    Created the file.
**
**
*/


#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("author", "Gambit");
  set("short","Mother Gorilla");
  set("long",@ENDTEXT
This is a large, brown, female gorilla.  She appears to be fairly gentle
but I wouldn't want to mess with her children!
ENDTEXT
);
  set_name("mother gorilla");
  set("id", ({
    "mother gorilla",
    "mother",
    "gorilla",
  }));
  credit(random(15) + random(15) + 10);
  set("damage", ({ 2, 7 }) );
  set("armor_class", 1);
  set("attack_strength", 10);
  set("race", "gorilla");
  set("gender", "female");
  set("weapon_name", "large fists");
  set_verbs( ({
    "punch at",
    "beat at",
}) );
  set_verbs2( ({
    "punches at",
    "beats at",
}));
  set_skill("defense", 1, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(2);
  set("chat_chance", 2);
  set("chat_output", ({
"The mother gorilla reels in one of her little ones as it strays too far.\n",
  "The mother gorilla picks a bug from her fur and eats it! Eeeoooh!\n",
}));
  set("forgetful", 0);
  set("att_chat_output", ({
  "The mother gorilla is enraged at the thought of harm to her children!\n",
  "The mother gorilla unleashes a loud roar as she charges you!\n",
  }) );
}
