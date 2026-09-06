#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

VALUE( 80 )
DISTANT( "a waterskin" )
SPECIFIC( "the waterskin" )
ALT_NAME( ({"skin"}) )
PLURAL( "waterskins" )
LOOK( "It's a waterskin made from some kind of animal hide. ?(HASINV:It's filled with $(INV).):(It's empty.)" )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 350 )
BULK( 1200 )
TASTE( "It tastes like camping." )

void create() {
   ::create();
/* OBJEDIT { */
   set_name("waterskin");
   set_bulk_capacity( 1000 );
   set_weight_capacity( 4000 );
/* } OBJEDIT */
}

object container_id( string val ) {
   return present( val, this_object() );
}

mapping query_aspects() {
   return ([ C_CLOTH, C_LEATHER ]);
}
