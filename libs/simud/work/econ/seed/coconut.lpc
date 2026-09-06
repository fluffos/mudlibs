inherit "/econ/seed/fruits";

NAME( "coconut" )
DISTANT( "a coconut" )
SPECIFIC( "the coconut" )
LOOK( "A furry brown coconut that looks difficult enough to eat." )
PLURAL( "coconuts" )
ALT_NAME( ({ "fruit", "seed" }) )
ALT_PLURAL( ({ "fruit", "seeds" }) )
TASTE( "It probably tastes better on the inside." )
FOOD_VALUE( 250 )
DRINK_VALUE( 100 )

// nutritiondata.com - raw meat of one medium coconut
WEIGHT( 397 )

FOOD_BUFF( (["con":1, "spd":1]) )
FOOD_BUFF_TIME( 10 )

void create() {
   ::create();
/* OBJEDIT { */
   set_plant_type( "/econ/trees/coconuttree" );
   set_use_msg( "~Name ~verbnibble ~targ." );
/* } OBJEDIT */
}

string query_treed_fruit_look() {
    return "0";
}

string query_floored_fruit_look() {
    return "%";
}

int query_treed_fruit_color() {
   return 0x23;
}

int on_consume(int max)
{
  //if (!default_consume(max, 0x1))
  //if (on_consume(max))
     msg("You crack open the coconut, exposing the sweet oily yumminess within.");
  //else
  return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_COCONUT ]) + ::query_aspects();
}
