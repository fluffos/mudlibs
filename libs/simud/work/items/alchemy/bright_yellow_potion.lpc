#include <const.h>
inherit "/obj/food";

NAME( "bright yellow potion" )
LOOK( "A small glass bottle full of glowing white liquid. A label has been attached that reads \"Drink Me!\"" )
DISTANT( "a bright yellow potion" )
SPECIFIC( "the bright yellow potion" )
PLURAL( "bright yellow potions" )
ALT_NAME( ({"potion", "yellow potion"}) )
ALT_PLURAL( ({"potions", "yellow potions"}) )
TASTE( "It tastes like distilled magic." )

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
   int amt = 100 + random( 4 * this_player()->query_stat("con") );
   int hp = this_player()->query_hp();
   int max_hp = to_int(this_player()->query_max_hp() * 2.25);

   if( hp + amt > max_hp )
      amt = max(max_hp - hp, 1);
   this_player()->set_hp( hp + amt );

   set_actor(this_player());
   set_target(this_object());
   this_player()->msg_local("~CEMO~Name ~verbdrink ~targ.~CDEF");
   if( amt > 50 )
      msg("You feel significantly better.");
   else if( amt > 1 )
      msg("You feel better.");
   else
      msg("You do not really feel any different.");
   destruct( this_object() );
   return 1;
}

mapping query_aspects() {
   return ([ C_LIQUID, C_POTION ]);
}
