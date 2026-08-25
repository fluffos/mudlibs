#include "path.h"

  inherit "/obj/monster";

  void setup() {
   set_name("dog");
   add_alias("dog");
    set_level(4);
    set_wimpy(0);
    set_random_stats(6,18);
   set_str(6);
   set_con(11);
   set_max_hp(20);
    set_gender (1);
    set_al (300);
   set_short("Dog");
set_main_plural("Dogs");
     add_plural("dogs");
set_long("Its a mutt. Probably a pure breed mutt.\n");
    set_aggressive (0);
  this_object()->init_equip();
add_move_zone("CAVE");
set_move_after(5,60);
  }
//#define AN this_object()->query_cap_name()
//#define DN this_player()->query_cap_name()
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack() {

  int two,three,four,five;
  two=random(2);
  three=random(3);
  four=random(4);
  five=random(5);

  return ([
    "punch"   :({ AN+" "+({"bites","mauls",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","mauls",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
    "kick"    :({ AN+" "+({"bites","chews",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"bites","chews",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
    "knee"    :({ AN+" "+({"gnaws","slashes",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"gnaws","bites",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
    "headbutt":({ AN+" "+({"hits","paws",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"hits","bites",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c

