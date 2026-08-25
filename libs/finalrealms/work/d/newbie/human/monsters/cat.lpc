#include "path.h"
inherit "/obj/monster";
string *colors = ({"tabby","brindle","black","ginger","tortoiseshell","white"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("alley cat");
    set_short("Alley cat");
    add_alias("cat");
    set_main_plural("alley cats");
    add_plural("cats");
    set_long("  A tough looking "+colors[i]+" cat. "
    "It looks as though it's capable of looking after itself, "
    "although it has clumps of fur missing here and there and a "
    "scratch or two."
    "\n");

    set_random_stats(2,5);
    set_str(5+i);
    load_chat(10,
       ({
        1,":meows!.",
        1,":hisses.",
        1,":washes its ears.",
        1,":attends to its personal hygiene.",
       }));
    load_a_chat(100,
      ({
       1,":claws at you!",
       1,":hisses angrilly.",
    }));
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






