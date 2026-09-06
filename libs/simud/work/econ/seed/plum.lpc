inherit "/econ/seed/fruits";

NAME( "plum" )
DISTANT( "a plum" )
SPECIFIC( "the plum" )
LOOK( "A smooth purple plum that looks juicy and delicious." )
PLURAL( "plums" )
ALT_NAME( ({ "fruit", "seed" }) )
ALT_PLURAL( ({ "fruit", "seeds" }) )
TASTE( "It tastes purple." )
FOOD_VALUE( 50 )
DRINK_VALUE( 25 )

// nutritionata.com - 2-1/8" diameter
WEIGHT( 66 )

FOOD_BUFF( (["int":1]) )
FOOD_BUFF_TIME( 5 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/plumtree" );
   set_use_msg( "~Name ~verbnibble ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
   return "o";
}

string query_floored_fruit_look() {
   return "%";
}

int query_treed_fruit_color() {
   return 0x25;
}

int on_consume(int max) {
   msg("You savour the sweet, juicy plum flavour.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_PLUM ]) + ::query_aspects();
}
