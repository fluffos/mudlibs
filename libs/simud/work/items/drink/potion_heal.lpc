inherit "/obj/ingredient";

/**
 * Please, nobody use this one. The current packaged potions are way more
 * effective - and use the approved math. - Al [Aug '05]
 */

NAME( "white potion" )
DISTANT( "a white potion" )
SPECIFIC( "the white potion" )
LOOK( "The potion is a pale white fluid, thinner than honey but thicker than milk. This type of potion greatly speeds healing, though one still needs to get enough rest." )
PLURAL( "white potions" )
ALT_NAME( ({ "potion", "healing potion", "heal potion" }) )
ALT_PLURAL( ({ "potions", "healing potions", "heal potions", "the white potions" }) )
WEIGHT( 1000 )
BULK( 800 )
TASTE( "It's salty, yet sweet. Refreshing, yet bland." )
GETTABLE( 1 )
DROPPABLE( 1 )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_drink_value( 1 );
/* } OBJEDIT */
}

int on_consume( int max ) {
   int ret;

   ::on_consume( max );
   msg("You feel a lot better.");
   this_player()->add_hp(20+random(this_player()->query_constitution()));
   return 1;
}

mapping query_aspects() {
   return ([ C_LIQUID, C_POTION ]);
}
