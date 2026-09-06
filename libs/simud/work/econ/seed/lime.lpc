inherit "/econ/seed/fruits";

NAME( "lime" )
DISTANT( "a lime" )
SPECIFIC( "the lime" )
LOOK( "A round green lime that looks savory yet sour." )
PLURAL( "limes" )
ALT_NAME( ({ "fruit" }) )
ALT_PLURAL( ({ "fruit" }) )
TASTE( "Tastes like a mixer." )
FOOD_VALUE( 18 )
DRINK_VALUE( 16 )

// nutritiondata.com - 2-1/8" dia
WEIGHT( 40 )

FOOD_BUFF( (["wil":2]) )
FOOD_BUFF_TIME( 3 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/limetree" );
   set_use_msg( "~Name ~verbnibble ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
   return ":";
}

string query_floored_fruit_look() {
    return "%";
}

int query_treed_fruit_color() {
   return 0x2A;
}

int on_consume(int max) {
   msg("You wrinkle your nose at the tart juiceness of this fruit.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_LIME, C_CITRUS ]) + ::query_aspects();
}
