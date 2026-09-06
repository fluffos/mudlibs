#include <const.h>
#include <object.h>
#include <container.h>
#include <inven.h>
#include <item.h>
#include <desc.h>

DISTANT( "a bag" )
SPECIFIC( "the bag" )
PLURAL( "bags" )
LOOK( "It's a small leather bag?(HASINV:, with $(INV) inside. The bag is $(CAPACITY)):(. It's empty).")
TASTE( "It tastes like burlap, and dirt. Mostly burlap." )

void create() {
/* OBJEDIT { */
   set_name("bag");
   set_gettable( 1 );
   set_droppable( 1 );
   set_bulk_capacity( 10000 );
   set_weight_capacity( 40000 );
/* } OBJEDIT */
   ::create();
}

mapping query_aspects() {
   return ([ C_CLOTH, C_LEATHER ]);
}
