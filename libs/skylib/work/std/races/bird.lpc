/* Bird race object.  Made by Ceres and stolen from the vulture object.
Modified by Dragonkin for new race system (this race shouldn't exist btw) */

inherit "/std/races/bird_base";

void setup() {
   set_name( "bird" );
   set_long( "A general, unspecified bird.\n" );
   set_height( 15 );
   set_weight( 60 );

   set_stats( ({ 0, 14, -4, -4, -6 }) );
} /* setup() */

void new_set_level( mixed *args ) {
   int weight;
   object thing;

   thing = args[ 1 ];
   if ( !thing )
     return;

   weight = (thing->query_weight() / 20);
  
   thing->add_ac( "blunt", "blunt", weight / 2 );
   thing->add_ac( "pierce", "pierce", weight );
   thing->add_ac( "sharp", "sharp", weight );
} /* new_set_level() */

void set_unarmed_attacks( object thing ) {
   int number;
  
   number = (int)thing->query_skill_bonus( "fighting.combat.melee.unarmed" );
   number = sqrt( number / 4 ) + ( thing->query_weight() / 20 );

   thing->remove_attack( "hands" );
   thing->remove_attack( "feet" );

   thing->remove_attack( "beak" );
   thing->remove_attack( "claws" );

   thing->add_attack( "beak", 50, ({ number / 2, 2, number / 2 }),
      "pierce", "unarmed", 0 );
   thing->add_attack( "claws", 75, ({ number, 5, number / 2 }),
      "sharp", "unarmed", 0 );

   thing->set_combat_response("dodge");
} /* set_unarmed_attacks() */

void eat_bit( mixed main_bits, object corpse, object race_obj,
              object eater ) {
   int which_bit;
   mixed *sub_bits;
   object new_bit;

   if( !eater ) return;

   which_bit = 3 * random( sizeof( main_bits ) / 3 );
   sub_bits = main_bits[ which_bit + 2 ];
   if( sizeof( sub_bits ) > 3 ) {
      call_out( "eat_bit", 0,
         race_obj->query_bit(
            sub_bits[ random( sizeof(sub_bits ) - 3 ) + 3 ] ),
            corpse, race_obj, eater );
      return;
   }

   if( member_array( main_bits[ which_bit ],
                    (mixed *)corpse->query_bits_left() ) == -1 ) {
      eater->remove_property( "busy" );
      return;
   }

   new_bit = corpse->make_bit( main_bits[which_bit] );
   corpse->add_bit_gone( main_bits[ which_bit ] );
   if( !( race_obj->query_eat( main_bits[ which_bit ] ) ) ) {
      tell_room( environment( eater ), "The " + (string)eater->short() +
         " rips " + add_a( main_bits[ which_bit ] ) + " from " +
         (string)corpse->short() + " and drops it.\n" );
      new_bit->move( environment(eater) );
      eater->remove_property( "busy" );
      return;
   }

   tell_room( environment( eater ), "The " + (string)eater->short() +
      " tears " + add_a( main_bits[ which_bit ] ) + " from " +
      (string)corpse->short() + " and begins eating.\n" );
   new_bit->dest_me();
   call_out( "finish_eating", 30 * sub_bits[ 1 ] +
             random( 60 * sub_bits[ 1 ] ) + random( 30 ), eater );
} /* eat_bit() */

void finish_eating( object eater ) {
   if( !eater )
      return;

   eater->remove_property( "busy", 1 );
} /* finish_eating() */

void player_heart_beat( string word, object eater ) {
   int i;
   object race_obj, *stuff;

   if( !environment( eater ) ) return;
   if( eater->query_property( "busy" ) ) return;
   stuff = all_inventory( environment( eater ) ) - ({ eater });
   if( !sizeof( stuff ) ) return;

   for( i = 0; i < sizeof( stuff ); i++ )
      if( !( stuff[ i ]->id( "corpse" ) ) ) {
      stuff -= ({ stuff[ i ] });
      i--;
   }

   if( !sizeof( stuff ) ) return;
   eater->add_property( "busy", 1 );
   i = random( sizeof( stuff ) );
   race_obj = stuff[ i ]->query_race_ob();
   call_out( "eat_bit", 0, race_obj->query_bits(), stuff[ i ], race_obj,
      eater );
} /* player_heart_beat() */
