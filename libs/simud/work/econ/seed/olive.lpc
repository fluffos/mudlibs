inherit "/econ/seed/fruits";

DISTANT( "an olive" )
SPECIFIC( "the olive" )
LOOK( "A small green olive which some people might find yummy." )
PLURAL( "olives" )
NAME( "olive" )
ALT_NAME( ({ "small olive", "green olive", "seed"}) )
ALT_PLURAL( ({ "small olives", "green olives", "fruit", "seeds" }) )
TASTE( "Shaken, not stirred." )
FOOD_VALUE( 5 )
DRINK_VALUE( 5 )

// nutritiondata.com - 'jumbo'
WEIGHT( 8 )

FOOD_BUFF( (["emp":1, "cha":1]) )
FOOD_BUFF_TIME( 1 )

void create() {
   ::create();
/* OBJEDIT { */
  set_plant_type( "/econ/trees/olivetree" );
   set_use_msg( "~Name ~verbnibble ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
    return ".";
}

string query_floored_fruit_look() {
    return "%";
}

int query_treed_fruit_color() {
   return 0x25;
}

int on_consume(int max) {
   msg("You taste the flavour of the oily, fleshy fruit.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_OLIVE ]) + ::query_aspects();
}
