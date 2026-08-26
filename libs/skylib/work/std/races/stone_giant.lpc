#include <bit.h>

#define SHADOW "/std/races/shadows/troll_race"

inherit "/std/races/humanoid";

void setup() {
   int i;

   set_name( "stone giant" );
   set_long( "The stone giants of the Ramtops are similar to trolls in the "
             "sense that they are made of stone.  They are much taller than "
             "your average troll though, roughly thirteen feet.\n" );
   set_height( 400 );
   set_weight( 80000 );
   set_desc( "a big looking giant apparantly made from stone" );

   remove_bit( "skin" );

/*
** Actually, it'd be nice to have all of these made of stone, so that
** stone-eaters (e.g. other trolls) can still eat them, but until then...
*/
   inedible = ({ });
   for( i = 0; i < sizeof( bits ); i += BIT_SIZE )
      inedible += ({ bits[ i + BIT_NAME ] });
   unrottable = ({ });
   for( i = 0; i < sizeof( bits ); i += BIT_SIZE )
      unrottable += ({ bits[ i + BIT_NAME ] });

   add_ac( "blunt", "blunt", 50 );
   add_ac( "pierce", "pierce", 15 );
   add_ac( "sharp", "sharp", 25 );

   set_sight( ({ 0, 5, 100, 125 }) );
   set_stats( ({ 14, -6, -6, 16, -4 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->add_attack( "hands", 75, ({ 40, 8, 10 }),
      "blunt", "unarmed", "unarmed_hands" );
   thing->add_attack( "feet", 25, ({ 60, 10, 40 }),
      "blunt", "unarmed", 0 );

   thing->set_combat_attitude("offensive");
} /* set_unarmed_attacks() */

void start_player( object thing ) {
   ::start_player( thing );
   clone_object( SHADOW )->setup_shadow( thing );
} /* start_player() */
