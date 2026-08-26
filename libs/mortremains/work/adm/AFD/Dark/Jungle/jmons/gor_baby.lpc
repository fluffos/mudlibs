/*
** FILE:    gor_baby.c
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
This is a cute little brown gorilla.  He frolics around playing with
anything that catches his eye.  He is so cute it would be a shame to
hurt him...and besides, I doubt his mother would like that much!
ENDTEXT
);
  set_name("male baby gorilla");
  set("id", ({
    "male baby gorilla",
    "male gorilla",
    "male baby",
    "male",
    "baby gorilla",
    "baby",
    "gorilla",
  }));
 credit(random(10) + random(10));
  set("damage", ({ 2, 3 }) );
  set("armor_class", 1);
  set("attack_strength", 8);
  set("race", "gorilla");
  set("gender", "male");
  set("weapon_name", "small fists");
  set_verbs( ({
    "punches at",
    "beats at",
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
  "The young gorilla rolls around in the grass playfully.\n",
}));
  set("forgetful", 1);
  set("att_chat_output", ({
  "The small gorilla seems to want to cry!\n",
"The young gorilla scurries around trying to hide!\n",
  }) );
}
