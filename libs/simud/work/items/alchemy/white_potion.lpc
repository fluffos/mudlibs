#include <const.h>
inherit "/obj/food";

NAME( "white potion" )
LOOK( "A small glass bottle full of glowing white liquid. A label has been attached that reads \"Drink Me!\"" )
DISTANT( "a white potion" )
SPECIFIC( "the white potion" )
PLURAL( "white potions" )
ALT_NAME( ({"potion"}) )
ALT_PLURAL( ({"potions"}) )
TASTE( "It tastes like magic." )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_drink_value( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 500 );
   set_bulk( 2 );
   set_value( 0 );
/* } OBJEDIT */
}

int on_consume( int max ) {
   int ret;
   this_player()->msg_local("~CEMO~Name ~verbdrink the white potion.~CDEF");
   msg("You feel a lot better.");
   this_player()->add_hp(75+random(2*this_player()->query_constitution()));
   destruct( this_object() );
   return 1;
}

mapping query_aspects() {
   return ([ C_LIQUID, C_POTION]);
}
