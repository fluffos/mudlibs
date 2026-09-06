inherit "/econ/seed/fruits";

NAME( "banana" )
DISTANT( "a banana" )
SPECIFIC( "the banana" )
LOOK( "A long yellow banana that looks good enough to eat." )
PLURAL( "bananas" )
ALT_NAME( ({ "fruit", "seed" }) )
ALT_PLURAL( ({ "fruit", "seeds" }) )
TASTE( "Probably better peeled." )
FOOD_VALUE( 75 )
DRINK_VALUE( 15 )

// nutritiondata.com - 7" to 7-7/8" long
WEIGHT( 118 )

FOOD_BUFF( (["cha":1]) )
FOOD_BUFF_TIME( 7 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/bananatree" );
   set_type( "seed" );
   set_use_msg( "~Name ~verbnibble ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
     return ")";
}

string query_floored_fruit_look() {
    return "%";
}

int query_treed_fruit_color() {
   return 0x2B;
}


int on_consume(int max) {
   msg("You savour the smooth, sweet banana flavour.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_BANANA ]) + ::query_aspects();
}
