inherit "/obj/food";

TASTE( "It tastes like dried goat stomach. Haggis, anyone?" )

void create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_edible( 0 );
   set_food_value( 0 );
   set_drink_value( 50 );
   set_use_msg( "~Name ~verbtake a swig from ~poss waterskin." );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 400 );
   set_bulk( 2500 );
   set_value( 12000 );
   set_distant( "a waterskin" );
   set_specific( "the waterskin" );
   set_look( "This is the stomach of a goat or some other small, "+
             "disgusting farm animal or another that has been "+
             "converted into a container for storing liquid so you "+
             "don't go all dehydrated on us. This particular model "+
             "has the added bonus of being magically enchanted to "+
             "remain completely full at all times." );
   set_plural( "waterskins" );
   set_name( "waterskin" );
   set_alt_name( "skin" );
   set_type( "food" );
/* } OBJEDIT */
}

int on_consume( int max ) {
   default_consume( max, 0x2 );
   return 1;
}
