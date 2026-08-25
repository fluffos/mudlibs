#include "path.h"
inherit "/obj/monster";
string *colors = ({"long spiral","cowrie","round pink","squat spiral",
                    "grey and green","large white"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("hermit crab");
    set_short("Hermit crab");
    add_alias("crab");
    set_main_plural("crabs");
    set_long("  A large hermit crab with a "+colors[i]+" shell. "
    "It's just crawling slowly along minding its own business. "
    "\n");

    set_random_stats(2,5);
    set_dex(5+i);
   set_gender(0);
    load_chat(10,
       ({
        1,":wombles around.",
        1,":clatters its claws at you.",
        1,":mumbles over something disgusting it found in the sand.",
       }));
    load_a_chat(100,
      ({
       1,":snaps its claws at you!",
       1,":spits green slime at you.",
    }));
    set_wimpy(10);
    set_level(3+random(3)+i);
    set_move_after(3,3);
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
    "punch"   :({ AN+" "+({"bites","scratches","claws",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","scratches","claws",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "kick"    :({ AN+" "+({"bites","scratches","claws",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","scratches","claws",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "knee"    :({ AN+" "+({"bites","scratches","claws",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","scratches","claws",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
    "headbutt":({ AN+" "+({"bites","scratches","claws",})[three]+" "+DN+" on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","scratches","claws",})[three]+" you on the "+({"arm","hand","leg","neck","thigh",})[five]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c







