inherit "/econ/seed/fruits";

NAME( "orange" )
DISTANT( "an orange" )
SPECIFIC( "the orange" )
LOOK( "A smooth, firm orange that looks good enough to eat." )
PLURAL( "oranges" )
ALT_NAME( ({ "fruit", "seed" }) )
ALT_PLURAL( ({ "fruit", "seeds" }) )
TASTE( "It tastes like high fructose corn syrup." )
FOOD_VALUE( 25 )
DRINK_VALUE( 30 )

// nutritiondata.com - 2-5/8" diameter
WEIGHT( 131 )
		
FOOD_BUFF( (["dex":1]) )
FOOD_BUFF_TIME( 2 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/orangetree" );
   set_use_msg( "~Name ~verbnibble ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
   return "*";
}

string query_floored_fruit_look() {
   return "%";
}

int query_treed_fruit_color() {
   return 0x29;
}

int on_consume(int max) {
   msg("You savour the sweet tangy orange flavour.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_ORANGE, C_CITRUS ]) + ::query_aspects();
}
