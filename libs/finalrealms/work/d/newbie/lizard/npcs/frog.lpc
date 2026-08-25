// Killer Frog
//  Tek
 
#include "/w/sojan/combat/unarmed_combat.h"
inherit "/obj/monster";
 
void setup() {
   set_name("frog");
   set_short("Killer frog");
   add_move_zone("newbie_river");
set_long("This is a small, vicious frog. It is dark green and has a "
 "mouth full of teeth.\n");
   set_main_plural("killer frogs");
   add_plural("frogs");
   set_gender(1+random(2));
   set_race("frog");
   set_random_stats(4, 8);
set_level(2);
set_damage_dice(1,3);
   set_al(-20);
 
 
} /* setup() */
 
mapping valid_attack() {
   return([
      "knee" : ({ AN+" sinks its teeth into "+DN+".\n",
                  "You sink your teeth into "+DN+".\n",
                  AN+" sinks its teeth into you.\n" }),
      "punch": ({ AN+" bites a chunk out of "+DN+".\n",
                  "You bite a chunk out of "+DN+".\n",
		  AN+" bites a chunk out of you.\n" }),
      "kick" : ({ AN+" rips some flesh out of "+DN+".\n",
                  "You rip some flesh out of "+DN+".\n",
                  AN+" rips some flesh out of you.\n" })
   ]);
 
} /* valid_attack() */
