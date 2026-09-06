inherit "/obj/ingredient";

NAME( "water" )
DISTANT( "water" )
SPECIFIC( "the water" )
LOOK( "Water, plain and simple." )
PLURAL( "water" )
WEIGHT( 1000 )
BULK( 1000 )
TASTE( "It doesn't really taste like anything." )
FOOD_VALUE( 0 )
DRINK_VALUE( 1000 ) // per 1000


create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_use_msg( "~Name ~verbtake a drink of water." );
   set_quantity( 250 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_LIQUID, C_WATER, C_RAW ]);
}
