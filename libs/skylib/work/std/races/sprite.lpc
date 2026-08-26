/*  Sprite  *
 *  Gototh  *
 * 25/06/97 */

inherit "/std/races/humanoid";

void setup() {
   set_name( "sprite" );
   set_long( "This is a small but fierce humanoid creature with sharp "
      "claws.  They are playfully evil in a similar way to elves, but not "
      "nearly as dangerous.\n" );
   set_desc( "a nasty playfully evil short humanoid with sharp claws" );

   // About the height of a child.
   set_height(100);
   // About the weight of a child.
   set_weight(600);

   // Can see in the dark, but gets blinded by light.
   set_sight( ({ 0, 0, 75, 90 }) );
   // Agile, intelligent, not very strong, and foolish.
   set_stats( ({ 0, 8, 2, -2, -2 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt(number) / 2;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );
   thing->remove_attack( "standard" );

   thing->remove_attack( "claws" );

   thing->add_attack( "claws", 75, ({ 3 * number, 20, number }), 
      "sharp", "unarmed", 0 );
} /* set_unarmed_attacks() */
