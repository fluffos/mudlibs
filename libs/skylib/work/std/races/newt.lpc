inherit "/std/races/amphibian";
 
void setup() {
   set_name( "newt" );
   set_long( "Newts are amphibians.\n");
   set_height( 5 );
   set_weight( 5 );  
   set_desc( "a newt, the type that lives in wells and is eaten by "
      "gnomes." );

   set_stats( ({ -4, 6, -6, -4, -6 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->remove_attack( "standard" );

   thing->remove_attack( "bite" );

   thing->add_attack( "bite", 50, ({ 10, 2, 6 }), 
      "pierce", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */
