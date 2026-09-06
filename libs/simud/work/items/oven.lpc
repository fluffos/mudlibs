#include <const.h>
#include <container.h>
inherit "/obj/scenery";

ICON( '#', 3, 4 )
TASTE( "It burns ~poss tongue!" )

void create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a stone oven" );
   set_specific( "the stone oven" );
   set_look( "This is an oven made from stones stacked into a funnel shape. It is enchanted, so it burns continually, even though there is no fuel in the firebox below. There is a large opening in the face of it, about chest height, into which things may be placed. The top of the oven peaks into a funnel, above which the heat distorts the air.?(HASINV: Cooking inside the oven $(ISINV) $(INV))" );
   set_plural( "ovens" );
   set_name( "oven" );
   set_alt_name( ({ /* Converted Array, Length = 1 */
  "stone oven"
}) );
   set_phrase( "A stone oven is ~plac, and is burning cheerily." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
   call_out( "heat_contents", 30 );
}

void on_insert( object ob ) {
   if( find_call_out("heat_contents") == -1 )
      call_out( "heat_contents", 30 );
}

void heat_contents() {
   object ob;

   // So that if it gets called externally, we don't
   // increase heating speed!
   remove_call_out( "heat_contents" );
   if( first_inventory() )
      call_out( "heat_contents", 30 );

   foreach( ob : all_inventory(this_object()) )
      ob->on_heat( 150 );
}
