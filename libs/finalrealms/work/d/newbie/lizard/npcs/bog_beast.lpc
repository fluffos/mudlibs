#include "unarmed_combat.h"
inherit "/obj/monster";
 
void setup() {
   set_name("bogbeast");
set_short("Bogbeast");
   set_long("  This creature standing here oozing with slime seems "
            "to be part human and part plant.  The beast has long "
            "root-like fingers that extend from a trunk of an arm.  "
            "Its face and body are covered with decaying vines and " 
            "leaves.  The vines hang off like tentacles and reach "
            "toward you.  "
            "\n\n");
   set_main_plural("bogbeasts");
   set_gender(0);
   set_race("unknown");
   set_guild("fighter");
   set_random_stats(5, 7);
   adjust_str(14);
   adjust_con(1);
   adjust_dex(18);
   set_aggressive(1);
   set_level(3);
   set_al(random(10));
   set_wimpy(0);
 
 
 
} /* setup() */
 
mapping valid_attack()
{
   return([
   "punch"    : ({ AN+" grabs a hold of "+DN+"'s neck.\n",
                   "You bite "+DN+"'s stem.\n",
                   AN+" strangles your neck.\n" }),
   "kick"     : ({ AN+" tries to pull off "+DN+"'s leg.\n",
                   "You try to pull "+DN+" from your body.\n",
                   AN+" grabs ahold of your leg.\n" }),
  "headbutt"   : ({ AN+" almost pulls "+DN+"'s arm off\n",
                   "You try to wiggle free from "+AN+".\n",
                   AN+" almost pulls your arm off.\n" }),
   ]);
 
} /* valid_attack() */
