// Quipper Fish
//  Tek
 
#include "unarmed_combat.h"
inherit "/obj/monster";
 
void setup() {
   set_name("centipede");
   set_short("centipede");
set_long("This is a large black centipede, these nasty creatures "
  "are found nearly everywhere. They are aggressive and rush forth "
    "to bite their prey. Hopefully this one is not poisonous.\n");
   set_main_plural("centipedes");
   add_plural("centipedes");
   set_gender(1+random(2));
   set_race("insect");
   set_random_stats(7, 15);
set_aggressive(1);
set_level(5);
set_damage_dice(1,4);
   set_al(-20);
 
 
} /* setup() */
 
mapping valid_attack()
{
   return([
      "knee" : ({ AN+" sinks its teeth into "+DN+".\n",
                  "You sink your teeth into "+DN+".\n",
                  AN+" sinks its teeth into you.\n" }),
      "punch": ({ AN+" bites a chunk out of "+DN+".\n",
                  "You bite a chunk out of "+DN+".\n",
		  AN+" bites a chunk out of you.\n" }),
      "kick" : ({ AN+" rips some flesh out of "+DN+".\n",
                  "You rip some flesh out of "+DN+".\n",
               AN+" bites a chunk out of "+DN+".\n" }),
     "headbutt":    ({  AN+" chews on "+DN+".\n",
                       "YOU CHEW SOMEONE.\n",
                     AN+"chews on you.\n"})
   ]);
 
} /* valid_attack() */
