inherit "/std/races/carnivore";

void setup() {
   set_name( "sphinx" );
   set_long( "A winged female monster in mythology having a woman' head and "
         "a lion's body and noted for killing anyone unable to answer its "
         "riddle.\n" );
   set_height( 10000 );
   set_weight( 1000000 );
   set_desc( "a mythical, but quite real, sphinx" );

   add_ac( "blunt", "blunt", 50 );
   add_ac( "pierce", "pierce", 20 );
   add_ac( "sharp", "sharp", 20 );

   remove_bit( "torso" );

   add_bit( "torso", "body", ({ 0, 200, 0,
      "heart", "liver", "left kidney", "right kidney", "left lung",
      "right lung", "spleen", "intestine", "pancreas", "left wing",
      "right wing" }) );
   add_bit( "left wing", "wing", ({ "torso", 20, 0 }) );
   add_bit( "right wing", "wing", ({ "torso", 20, 0 }) );

   inedible += ({ "left wing", "right wing" });

   set_stats( ({ 20, -8, -4, 20, -4 }) );
} /* setup() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "claws" );
   thing->remove_attack( "chew" );

   thing->add_attack( "claws", 75, ({ 2 * number, 8, number }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "chew", 75, ({ 3 * number, 10, number }),
      "sharp", "unarmed", 0 );
} /* set_unarmed_attacks() */
