#include "path.h"

inherit "/obj/monster";

void setup() {
    set_name("rat");
    set_wimpy(0);
    set_random_stats(6,18);
    set_str(6);
    set_con(11);
    set_gender (1);
    set_al (10);
    set_short("Rat");
    set_level(4);
    set_max_hp(6);
    set_main_plural("rats");
    add_plural("rats");
    set_long("This is a huge rat.  It  is the size of a "
      "small dog.  It's razor sharp teeth and claws make it "
      "look as if this beast could be a dangerous foe.  "
      "\n\n");
    set_aggressive (0);
    add_move_zone("CAVE");
    set_move_after(5,60);
}
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack () {

    int two,three,four,five;
    two=random(2);
    three=random(3);
    four=random(4);
    five=random(5);

    return ([
      "punch"   :({ AN+" "+({"claws","scratches",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"claws","scratches",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
      "kick"    :({ AN+" "+({"bites","chews",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"bites","chews",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
      "knee"    :({ AN+" "+({"gnaws","slashes",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"gnaws","slashes",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
      "headbutt":({ AN+" "+({"gnaws","chews",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
	"You hit "+DN+".\n",
	AN+" "+({"claws","slashes",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
    ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c

