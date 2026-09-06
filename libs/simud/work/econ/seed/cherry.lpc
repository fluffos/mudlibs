inherit "/econ/seed/fruits";

NAME( "cherry" )
DISTANT( "a cherry" )
SPECIFIC( "the cherry" )
LOOK( "A deep-red cherry that looks juicy and delicious." )
PLURAL( "cherries" )
ALT_NAME( ({ "fruit", "seed" }) )
ALT_PLURAL( ({ "fruit", "seeds" }) )
TASTE( "It tastes like you can't eat just one." )
FOOD_VALUE( 10 )
DRINK_VALUE( 5 )

// no official data to back this value up
WEIGHT( 5 )

FOOD_BUFF( (["wil":2]) )
FOOD_BUFF_TIME( 1 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/cherrytree" );
   set_use_msg( "~Name ~verbgulp ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
    return ":";
}

string query_floored_fruit_look() {
    return "%";
}

int query_treed_fruit_color() {
   return 0x21;
}

int on_consume(int max) {
   msg("You savour the sweet, juicy cherry flavour.");
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_CHERRY ]) + ::query_aspects();
}
