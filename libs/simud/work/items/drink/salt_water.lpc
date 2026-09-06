inherit "/obj/ingredient";

NAME( "salt water" )
DISTANT( "salt water" )
SPECIFIC( "the salt water" )
LOOK( "Icky salt water." )
PLURAL( "salt water" )
WEIGHT( 1000 )
BULK( 1000 )
TASTE( "Ick, salty!." )
FOOD_VALUE( 0 )
DRINK_VALUE( -10 ) // per 1000


create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_use_msg( "~Name ~verbtake a drink of salt water." );
   set_quantity( 250 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_LIQUID, C_SALT, C_WATER, C_RAW ]);
}
