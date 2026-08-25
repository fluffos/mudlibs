#include "path.h"
inherit "/obj/monster";
string *colors = ({"black and tan","dirty yellow","black","brown with a grey muzzle","black and white"});
void setup()
{
    int i;
    i = random(sizeof(colors));
    set_name("mongrel");
    set_short("Mongrel");
    add_alias("dog");
    set_main_plural("dogs");
    add_plural("mongrels");
    set_long("  A mangy looking cur, it cringes away as you approach. "
    "it's "+colors[i]+" where it still has hair, "
    "one ear is torn, and it seems to have a bad limp. "
    "From the look of it you'd be doing it a favour if you killed it. "
    "\n");

    set_random_stats(2,5);
    set_str(5+i);
    load_chat(100,
       ({
        1,":barks!.",
        1,":cringes.",
      1,":whimpers.",
      1,":cowers.",
        1,":licks its wounded paw.",
        1,":raises one leg and relieves itself on your foot.",
       }));
    load_a_chat(100,
      ({
       1,":growls!",
       1,":snarls!",
    }));
    set_wimpy(50);
    set_level(1+random(3)+i);
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






