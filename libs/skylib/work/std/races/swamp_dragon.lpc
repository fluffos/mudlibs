inherit "/std/races/reptile_base";

void setup() {
   set_short( "swamp dragon" );
   set_name( "dragon" );
   set_long( "A cute little swamp dragon" );
   set_weight( 100 );
   set_height( 40 );
   set_desc( "a cute looking swamp dragon" );

   set_stats( ({ -2, 2, -4, 0, -2 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "bite" );
   thing->remove_attack( "tail" );

   thing->add_attack( "bite", 75, ({ 3 * number, number / 2, number }),
      "pierce", "unarmed", 0 );
   thing->add_attack( "tail", 75, ({ number, 5, number }),
      "blunt", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */
