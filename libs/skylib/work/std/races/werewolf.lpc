inherit "/std/races/humanoid";

void setup() {
   set_long( "The werewolf, the lupine, the lycanthrope.\n" );
   set_name( "werewolf" );
   set_weight( 2000 );
   set_height( 200 );

   add_ac( "blunt", "blunt", 3 );
   add_ac( "pierce", "pierce", 2 );
   add_ac( "sharp", "sharp", 2 );

   set_sight( ({ 5, 20, 200, 300 }) );
   set_stats( ({ 0, 4, -2, 4, -2 }) );
} /* setup() */

string query_desc( object thing ) {
   if( (int)thing->query_gender() == 1 )
      return "He is a horrible monster.\n";
   if( (int)thing->query_gender() == 2 )
      return "She is a horrible monster.\n";

   return "It is a horrible monster.\n";
} /* query_desc() */


void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number ) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "claws" );
   thing->remove_attack( "bite" );

   thing->add_attack( "claws", 75, ({ 32, 5, 15 }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "bite", 25, ({ 60, 10, 50 }),
      "pierce", "unarmed", 0 );
} /* set_unarmed_attacks() */
