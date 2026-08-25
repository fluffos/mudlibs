#include "path.h"
inherit "/obj/monster";

void setup()
{
    set_name("bandicoot");
    set_short("Bandicoot");
    set_long("   The bandicoot looks like a cat thats been eating "
    "some of the mushrooms round here. It is a brindled grey with "
    "brown rings down it's body, a long nose and a mouthfull of sharp "
    "teeth suggest that it's a meat eater of some sort. "
    "It snuffles around in the fallen leaves as it waddles along. "
    "\n");
    set_random_stats(2,5);
    set_move_after(3,1);
    set_str(10);
    set_max_hp(20);
    load_chat(100,
       ({
        1,":scrounges round in the leaves on the forest floor.",
        1,":crunches something small and unidentified.",
        1,":eyes you suspiciously.",
        1,":scratches vigorously.",
       }));
    load_a_chat(100,
      ({
       1,":hisses.",
    }));
      1,":snarls.",
    set_level(6+random(6));
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
    "punch"   :({ AN+" "+({"bites","claws","scratches",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","claws","scratches",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"bites","claws","scratches",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","claws","scratches",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"bites","claws","scratches",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","claws","scratches",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"bites","claws","scratches",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","claws","scratches",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c






