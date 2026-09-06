#include <const.h>
#include <container.h>
#include <fire.h>
inherit "/obj/scenery";

NAME( "oven" )
DISTANT( "a stone oven" )
SPECIFIC( "the stone oven" )
LOOK( "This is an oven made from stones stacked into a funnel shape. ?(HASFUEL:The firebox below the oven has fuel in it, ?(ISLIT:and it is burning brightly):(but it is still unlit, and the oven is cold and dark)):(The firebox is empty, and the oven cold and dark). There is a large opening in the face of it, about chest height, into which you can put things that you would like to cook. The top of the oven peaks into a funnel?(ISLIT:, above which the heat distorts the air).?(HASINV: ?(ISLIT:Cooking):(Sitting) inside the oven $(ISINV) $(INV).)" )
PLURAL( "ovens" )
ALT_NAME( ({ "stone oven", "oven" }) )
PHRASE( "A stone oven is ~plac, ?(ISLIT:and is burning cheerily.):(but it is cold and dark.)" )
ICON( '#', 3, 4 )
TASTE( "It burns ~poss tongue! Didn't your mother tell you not to taste ovens?" )

void create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_insert( object ob ) {
   if( ob->query_fuel() ) {
      add_fuel( ob );
      set_actor(this_player());
      msg_room( environment(), "~CACT~Name ~verbadd fuel to the firebox.~CDEF" );
   }
}

void on_ignite() {
   msg_room( environment(), "~CACTThe oven's firebox bursts into flame!~CDEF" );
}

void on_extinguish() {
   msg_room( environment(), "~CACTAs the last of the fuel in the firebox burns to ashes, the oven goes out and starts to cool.~CDEF" );
}
