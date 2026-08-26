inherit "/std/races/carnivore";

void setup() {
   set_name( "chimera" );
   set_desc( "a chimera" );
   set_height( 250 );
   set_weight( 4000 );

   set_stats( ({ 8, 10, -4, 14, -4 }) );
} /* setup() */

void new_set_level( mixed *args ) {
   int level;
   object thing;

   if( sizeof(args) < 2 || !args[1] )
      return;

   level = args[ 0 ];
   thing = args[ 1 ];

   thing->add_skill_level( "general.health", level * 2 );
   thing->add_ac( "blunt", "blunt", level / 2 );
   thing->add_ac( "pierce", "pierce", level / 4 );
   thing->add_ac( "sharp", "sharp", level / 3 );
} /* new_set_level() */

int query_dark( int light ) { return 0; }

void set_unarmed_attacks( object thing ) {
   int number;

   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = 4 + sqrt( number );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "claws" );
   thing->remove_attack( "bite" );
   thing->remove_attack( "fire" );

   thing->add_attack( "claws", 75, ({ 2 * number, 8, number }),
      "sharp", "unarmed", 0 );
   thing->add_attack( "bite", 75, ({ 3 * number, 10, number }),
      "pierce", "unarmed", 0 );
   thing->add_attack( "fire", 25, ({ 5 * number, 10, 2 * number }),
      "fire", "unarmed", 0 );

   thing->set_combat_response("dodge");
   thing->set_combat_attitude("offensive");
} /* set_unarmed_attacks() */
