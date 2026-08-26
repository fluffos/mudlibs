inherit "/std/races/humanoid";

void setup() {
   set_name( "dwarf" );
   set_long( "Dwarves are about four feet tall.  Stocky, bearded and "
      "usually wearing up to twelve layers of clothing makes it hard to "
      "tell the male dwarves from the female ones.\n" );
   set_desc( "a short bearded humanoid person of indeterminable sex" );
   set_weight( 1200 );
   set_height( 110 );

   set_sight( ({ 0, 5, 180, 200 }) );
   set_stats( ({ 2, 4, 0, 6, 2 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->add_attack( "hands", 75, ({ 2 * number, 8, number }),
      "blunt", "unarmed", 0 );
   thing->add_attack( "feet", 25, ({ 3 * number, 10, number }),
      "blunt", "unarmed", 0 );
} /* set_unarmed_attacks() */
