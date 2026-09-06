#include <const.h>
inherit "/obj/food";

NAME( "blue potion" )
LOOK( "A small glass bottle full of glowing blue liquid. A label has been attached that reads \"Drink Me!\"" )
DISTANT( "a blue potion" )
SPECIFIC( "the blue potion" )
PLURAL( "blue potions" )
ALT_NAME( ({"potion", "mana potion"}) )
ALT_PLURAL( ({"potions", "mana potions"}) )
PERISHABLE( 8000 ) // Several months
TASTE( "It makes your tongue tingle in anticipation." )

create() {
   ::create();
/* OBJEDIT { */
   set_drinkable( 1 );
   set_drink_value( 0 );
   set_use_msg( "~Name ~verbdrink ~targ." );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 500 );
   set_bulk( 2 );
   set_value( 0 );
/* } OBJEDIT */
}

int on_consume( int max ) {
   msg("You feel mana pulsing through your veins.");
   this_player()->add_mana(50+random(to_int(2.5*this_player()->query_empathy())));
   return ::on_consume(max);
}

mapping query_aspects() {
   return ([ C_LIQUID, C_POTION ]);
}
