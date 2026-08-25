
  inherit "/obj/monster";

  void setup() {
   set_name("roach");
    set_level(2);
    set_wimpy(0);
    set_random_stats(6,18);
   set_str(6);
   set_con(11);
   set_max_hp(5);
    set_gender (1);
    set_al (10);
   set_short("Big roach");
   set_main_plural("roaches");
     add_plural("roaches");
set_long("This is a large roach that is commonly found in these caves.\n");
  this_object()->init_equip();
add_move_zone("newbie_tunnel");
set_move_after(5,60);
  }
//#define AN this_object()->query_cap_name()
//#define DN this_player()->query_cap_name()
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

mapping valid_attack()
{

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
    "headbutt":({ AN+" "+({"hits","slaps",})[two]+" "+DN+" on the "+({"arm","hand","leg","neck",})[four]+".\n",
                 "You hit "+DN+".\n",
                  AN+" "+({"hits","slaps",})[two]+" you on the "+({"arm","hand","leg","neck",})[four]+".\n"}),
  ]);}

//For more information on this code see /w/sojan/combat/unarmed_combat.c

