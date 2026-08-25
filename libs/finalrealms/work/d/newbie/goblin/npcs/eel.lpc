// Giant eel
//  Tek
 
#include "/w/sojan/combat/unarmed_combat.h"
inherit "/obj/monster";
 
void setup() {
   set_name("eel");
   set_short("giant eel");
   add_move_zone("newbie_river");
set_long("A very large moray looking eel. It looks really hungry "
  "at the moment. It probably will not have a problem eating you "
  "with the size of its teeth.\n");
   set_main_plural("giant eels");
   add_plural("eels");
   set_race("fish");
   set_random_stats(7, 15);
set_aggressive(1);
set_level(5);
set_ac(6);
set_damage_dice(1,8);
   set_al(0);
 
 
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
                  AN+" rips some flesh out of you.\n" })
   ]);
 
} /* valid_attack() */
