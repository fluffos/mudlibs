#include <desc.h>
#include <item.h>
#include <saveload.h>
#include <object.h>

NAME( "flint and steel" )
DISTANT( "a flint and steel kit" )
SPECIFIC( "the flint and steel kit" )
LOOK( "The piece of flint is thumb-sized and has a sharp edge. It is " +
"rough and blackish gray. The piece of steel is just a curved scrap of " +
"metal.\n\n" +
"Flint and steel is the usual method for starting a fire. The flint is " +
"struck against the piece of steel, which makes sparks. The sparks are then " +
"caught by something very dry and flammable, such as tinder or charcloth. " +
"This small flame is then used to start a fire. You may ~CBRTuse~CDEF this " +
"flint and steel on ovens, fireplaces, or similar, to start fires in them, " +
"but they should have fuel in them first." )
ALT_NAME( ({ "flint", "kit", "flint and steel kit", "flint and steel" }) )
PLURAL( "flint and steel kits" )
ALT_PLURAL( ({ "kits", "flints", "flint and steels" }) )
GETTABLE( 1 )
DROPPABLE( 1 )

int on_use( object target ) {
   if( !target ) {
      msg("What would you like to try and ignite?");
      return 1;
   }
   if( !target->query_is_burnable() ) {
      msg("You can't ignite that.");
      return 1;
   }
   if( target->query_lit() ) {
      msg("It has already been ignited.");
      return 1;
   }
   if( target->query_fuel() <= 0 ) {
      msg( "There is no fuel to ignite. You'll need to add some." );
      return 1;
   }
   set_target(target);
   this_player()->msg_local( "~CACT~Name ~verbstrike ~poss flint, throwing sparks into ~targ.~CDEF" );
   target->set_lit( 1 );
   //set_lit() already calls on_ignite()
   //target->on_ignite();
   return 1;
}
