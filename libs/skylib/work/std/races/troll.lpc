#include <bit.h>

#define SHADOW "/std/races/shadows/troll_race"

inherit "/std/races/humanoid";

void setup() {
   int i;

   set_name( "troll" );
   set_long( "Trolls are a (usually) silicareous but humanoid life-form.  "
         "They are traditionally strong, hardy and incredible long-lived.\n" );
   set_height( 250 );
   set_weight( 20000 );
   set_desc( "a well-muscled humanoid apparently made from stone, in "
         "other words, a troll" );

   remove_bit( "skin" );

/*
 * Actually, it'd be nice to have all of these made of stone, so that
 * stone-eaters (e.g. other trolls) can still eat them, but until then...
*/
   inedible = ({ });
   for ( i = 0; i < sizeof( bits ); i += BIT_SIZE )
      inedible += ({ bits[ i + BIT_NAME ] });
   unrottable = ({ });
   for ( i = 0; i < sizeof( bits ); i += BIT_SIZE )
      unrottable += ({ bits[ i + BIT_NAME ] });

   add_ac( "blunt", "blunt", 50 );
   add_ac( "pierce", "pierce", 15 );
   add_ac( "sharp", "sharp", 25 );

   add_attack( "hands", 75, ({ 40, 8, 10 }) );
   add_attack( "feet", 25, ({ 60, 10, 40 }) );

   set_sight( ({ 0, 5, 100, 125 }) );
   set_stats( ({ 8, -4, -4, 12, -2 }) );
} /* setup() */

void start_player( object thing ) {
   ::start_player( thing );
   clone_object( SHADOW )->setup_shadow( thing );
} /* start_player() */
