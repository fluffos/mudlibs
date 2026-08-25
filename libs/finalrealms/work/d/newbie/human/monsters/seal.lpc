#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("seal");
    set_short("Seal");
    set_long("   A large seal, it's just lying around doing nothing in "
    "particular. It's a deep brown color, and for something that spends "
    "so much time in the water, it smells pretty bad. \n");
    set_random_stats(12,5);
    set_move_after(30,10);
    set_max_hp(20);
   set_al(-250);
    load_chat(100,
       ({
        1,":rolls over.",
        1,":flips sand over itself.",
        1,":eyes you cautiously.",
        1,"'arf!",
//    1,":arfs loudly.",
        1,":scratches itself slowly."
       }));
    load_a_chat(100,
      ({
       1,":snaps at you.",
       1,":snarfles angrilly."
    }));
    set_level(6+random(12));
   set_gender(0);

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
    "punch"   :({ AN+" "+({"bites","thwoks","thwaps",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","thwaps",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"bites","thwoks","thwaps",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","thwaps",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"bites","thwoks","thwaps",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","thwaps",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"bites","thwoks","thwaps",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","thwoks","thwaps",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c


