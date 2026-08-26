inherit "/std/races/rodent_base";

void setup(){
   set_name( "rabbit" );
   set_long( "A wascally wabbit it is!\n" );
   set_desc( "a fuzzy, but evil bunny" );
   set_height( 30 );
   set_weight( 150 );

   remove_bit( "left eye" );
   remove_bit( "right eye" );
   remove_bit( "tail" );

   add_bit( "left eye", "eye", ({ "head", 1,
      ({ "/d/sur/Scrogden/items/bunnyeye",1 }) }) );
   add_bit( "right eye", "eye", ({ "head", 1,
      ({ "/d/sur/Scrogden/items/bunnyeye", 1 }) }) );
   add_bit( "cotton tail", "tail", ({ 0, 5,
      ({ "/d/sur/Scrogden/items/cottontail", 1 }) }) );

   set_stats( ({ -2, 8, -6, -4, -6 }) );
} /* setup() */

void new_set_level( mixed *args ) {
   int level;
   object thing;

   if( sizeof(args) < 2 || !args[1] )
      return;

   level = args[ 0 ];
   thing = args[ 1 ];
   
   thing->add_ac( "blunt", "blunt", level );
   thing->add_ac( "sharp", "sharp", 2 + level );
   thing->add_ac( "pierce", "pierce", 2 * level );
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = number / 10;

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "bite" );
   thing->remove_attack( "claws" );

   thing->add_attack( "bite", 75, ({ 0, 5, number }),
      "pierce", "unarmed", 0 );
   thing->add_attack( "claws", 50, ({ 0, 3, number / 2 }),
      "sharp", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */
