// Quipper Fish
//  Tek
 
#include "unarmed_combat.h"
inherit "/obj/monster";
 
void setup() {
   set_name("quipper");
   set_short("quipper");
   add_move_zone("newbie_river");
   set_move_after(10, 30);
set_long("This is a small, vicious fish. It is dark green and has a "
 "mouth full of teeth. It is closely related to the pirahna.\n");
   set_main_plural("quippers");
   add_plural("quippers");
   set_gender(1+random(2));
   set_race("fish");
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
               AN+" rips some flesh out of you.\n" }),
     "headbutt":    ({  AN+" chews on "+DN+".\n",
                       "YOU CHEW SOMEONE.\n",
    AN+" chews on you.\n"})
   ]);
 
} /* valid_attack() */
