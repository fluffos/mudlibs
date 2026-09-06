inherit "/econ/seed/fruits";

NAME( "apple" )
DISTANT( "an apple" )
SPECIFIC( "the apple" )
LOOK( "A shiny red apple that looks good enough to eat." )
PLURAL( "apples" )
ALT_NAME( ({ "red apple", "fruit", "seed"}) )
ALT_PLURAL( ({ "red apples", "fruit", "seeds" }) )
TASTE( "That's it, everybody out of the garden." )
FOOD_VALUE( 50 )
DRINK_VALUE( 30 )

// nutritiondata.com - 2-3/4" dia, red
WEIGHT( 138 )

FOOD_BUFF( (["int":1]) )
FOOD_BUFF_TIME( 5 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/appletree" );
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
   return 0x89;
}

int on_consume(int max) {
   msg("You savour the tart, sweet apple flavour.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_APPLE ]) + ::query_aspects();
}
