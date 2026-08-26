/*
** FILE:    gor_baby2.c
** DATE:    20 Aug 1996
** PURPOSE: "Baby Gorilla" - A young brown gorilla for the jungle area.
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
  set("short","Baby Gorilla");
  set("long",@ENDTEXT
This is a cute little brown gorilla.  She is fairly calm for a baby and
seems to take an extreme interest in the things around her.  She is 
constantly looking around at different things in wonder.
ENDTEXT
);
  set_name("baby gorilla");
  set("id", ({
    "female baby gorilla",
    "female",
    "female baby",
    "female gorilla",
    "baby",
    "gorilla",
  }));
 credit(random(10) + random(10));
  set("damage", ({ 2, 3 }) );
  set("armor_class", 1);
  set("attack_strength", 8);
  set("race", "gorilla");
  set("gender", "female");
  set("weapon_name", "small fists");
  set_verbs( ({
    "punch at",
    "beat at",
}));
  set_verbs2( ({
    "punches at",
    "beats at",
}));
  set_skill("defense", 1, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(1);
  set("chat_chance", 2);
  set("chat_output", ({
  "The small gorilla looks around her in wonder.  How cute!\n",
}));
  set("forgetful", 1);
  set("att_chat_output", ({
  "She's only a little girl!  Why hurt her?\n",
"The young gorilla scurries around trying to hide!\n",
  }) );
}
