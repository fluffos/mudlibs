inherit "/std/races/ruminant";

void setup() {
   mixed *new_head;

   set_name( "buffalo" );
   set_long( "A water buffalo, a large hairy mammal, as opposed to a water "
      "melon, a large green fruit.\n" );
   set_height( 175 );
   set_weight( 18000 );
   set_desc( "a large, very hairy quadruped, like a cow but hairier" );

   new_head = query_bit( "head" );
   new_head[ 2 ] += ({ "left horn", "right horn" });
   remove_bit( "head" );
   add_bit( "head", "head", new_head[ 2 ] );
   add_bit( "left horn", "horn", ({ "head", 20, 0 }) );
   add_bit( "right horn", "horn", ({ "head", 20, 0 }) );
   add_bit( "udders", "udders", ({ 0, 60, 0 }) );
   add_bit( "tail", "tail", ({ 0, 18, 0 }) );

   inedible += ({ "left horn", "right horn", "tail" });  
   unrottable += ({ "left horn", "right horn" });

   add_ac( "blunt", "blunt", 50 );
   add_ac( "pierce", "pierce", 20 );
   add_ac( "sharp", "sharp", 20 );

   add_attack( "bite", 20, ({ 40, 8, 10 }) );
   add_attack( "feet", 50, ({ 60, 10, 40 }) );

   set_stats( ({ 4, -2, -6, 8, -6 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "horns" );
   thing->remove_attack( "hoof" );

   if( number < 10 )
      number = 10;
  
   thing->add_attack( "horns", 40, ({ 60, 10, 40 }), 
      "pierce", "unarmed", 0 );
   thing->add_attack( "hoof", 60, ({ 40, 8, 10 }), 
      "blunt", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */
