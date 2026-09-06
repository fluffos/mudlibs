inherit "/econ/seed/fruits";

NAME( "lemon" )
DISTANT( "a lemon" )
SPECIFIC( "the lemon" )
LOOK( "A small yellow lemon that looks juicy and tart!" )
PLURAL( "lemons" )
ALT_NAME( ({ "fruit" }) )
ALT_PLURAL( ({ "fruit" }) )
TASTE( "It tastes like a pine tree -- must be a glitch in the Matrix." )
FOOD_VALUE( 20 )
DRINK_VALUE( 18 )

// nutritiondata.com - 2-1/8" dia
WEIGHT( 58 )

FOOD_BUFF( (["wil":2]) )
FOOD_BUFF_TIME( 3 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/lemontree" );
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
   return 0x2B;
}

int on_consume(int max) {
   msg("You wrinkle your nose at the tart juiceness of this fruit.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_LEMON, C_CITRUS ]) + ::query_aspects();
}
