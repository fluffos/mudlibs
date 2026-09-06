#include <const.h>
inherit "/obj/trinket";

DISTANT( "a deer skin" )
SPECIFIC( "the deer skin" )
LOOK( "This deer skin is covered in rough fur." )
PLURAL( "deer skins" )
ALT_PLURAL( ({"skins", "pelts"}) )

void create() {
   ::create();
/* OBJEDIT { */
   set_name( "deer skin" );
   set_gettable( 1 );
   set_droppable( 1 );
   set_weight( 1 );
   set_bulk( 1 );
   set_value( 20 );
   set_alt_name( ({ "skin" }) );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_PELT, C_DEERSKIN ]);
}
