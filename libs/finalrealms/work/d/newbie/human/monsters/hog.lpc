#include "path.h"
inherit "/obj/monster";
string *types = ({"cute piglet","plump pig","sow","wild boar"});
void  setup()
{
    int i;
    i = random(sizeof(types));
    set_name("pig");
    set_short("Pig");
   add_alias("hog");
    set_long("  A "+types[i]+". "
    "It seems to be rummaging through the leaf litter here  "
    "looking for fallen jungle fruit and insects. "
    "\n");
   if(i == 2) gender = 2;
   if(i == 3) gender = 1;
   else gender = 1 + random(2);
    set_gender(gender);

    set_random_stats(2+i,5);
    set_str(5+(i*3));
    set_max_hp(10*i);
    set_dex(5+(10-i));

    load_chat(10,
       ({
        1,":snuffles.",
        1,":chomps up some slimey worms.",
        1,":plows through the leaf litter.",
        1,":crunches up a beetle.",
       }));
    load_a_chat(100,
      ({
       1,":snorts angrilly",
       1,":bleeds all over you.",
    }));
    //set_wimpy(100-(10*i));
    set_level(3+random(3)*i);
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








