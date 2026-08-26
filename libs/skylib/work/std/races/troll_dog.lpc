#include <bit.h>

#define SHADOW "/std/races/shadows/troll_race"

inherit "/std/races/carnivore";

void setup() {
   int i;
   set_name( "troll dog" );
   set_long( "Troll dogs are large dogs, but made from stone.\n" );
   set_desc( "a nasty troll dog" );
   set_height( 60 );
   set_weight( 4000 );

   remove_bit( "skin" );

/*
 * Actually, it'd be nice to have all of these made of stone, so that
 * stone-eaters (e.g. other trolls) can still eat them, but until then...
*/
   inedible = ({ });
   for( i = 0; i < sizeof( bits ); i += BIT_SIZE )
      inedible += ({ bits[ i + BIT_NAME ] });
   unrottable = ({ });
   for( i = 0; i < sizeof( bits ); i += BIT_SIZE )
      unrottable += ({ bits[ i + BIT_NAME ] });

   set_stats( ({ 8, 0, -4, 8, -6 }) );
} /* setup() */

void new_set_level( mixed *args ) {
   int level;
   object thing;

   if( sizeof(args) < 2 || !args[1] )
      return;

   level = args[ 0 ];
   thing = args[ 1 ];

   thing->add_ac( "blunt", "blunt", 80 );
   thing->add_ac( "sharp", "sharp", 20 );
   thing->add_ac( "pierce", "pierce", 10 );

   thing->add_skill_level( "other.perception", 250 );
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
   int number;
  
   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = sqrt( number );
  
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "claws" );
   thing->remove_attack( "bite" );

   thing->add_attack( "claws", 100, ({ ( 3 * number ) / 2, 5, number }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "bite", 50, ({ 3 * number, 2, number }),
      "pierce", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */

void start_player( object thing ) {
   ::start_player( thing );
   clone_object( SHADOW )->setup_shadow( thing );
} /* start_player() */

