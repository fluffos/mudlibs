#include "path.h"
inherit "/obj/monster";
string *colors = ({"brown","black and white spotted","silvery gray","thin green","bright red and pink spotted","yellow"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("snake");
    set_short("snake");
    set_long("  A small "+colors[i]+" snake just slithering along "
    "not bothering anyone, it looks a little lost to be honest. "
    "Why not help it find itself ? "
    "\n");

    set_random_stats(2,5);
    set_dex(10+i);
    load_chat(10,
       ({
        1,":hisses.",
        1,":tastes the air with its tongue.",
        1,":slithers on.",
       }));
    load_a_chat(100,
      ({
       1,":spits venom in your general direction.",
       1,":hisses angrilly.",
    }));
   set_gender(0);
    set_wimpy(10);
    set_level(3+random(3)+i);
}
//This is supposed to be code for modifying the unarmed combat
//of various creatures.  I am Talon; however, so not even the gods
//know how this will turn out...

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack () {

  int two,three,four,five;
  two=random(2);
  three=random(3);
  four=random(4);
  five=random(5);

  return ([
    "punch"   :({ AN+" "+({"bites","thwoks","squeezes",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","squeezes",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"bites","thwoks","squeezes",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","squeezes",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"bites","thwoks","squeezes",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","squeezes",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"bites","thwoks","squeezes",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","squeezes",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c








