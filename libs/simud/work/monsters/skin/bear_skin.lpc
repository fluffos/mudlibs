#include <const.h>
inherit "/obj/trinket";

DISTANT( "a bear skin" )
SPECIFIC( "the bear skin" )
LOOK( "This bear skin is covered in thick brown fur." )
PLURAL( "bear skins" )
ALT_NAME( ({ "skin", "pelt" }) )
ALT_PLURAL( ({ "skins", "pelts" }) )

void create() {
   ::create();
/* OBJEDIT { */
   set_name( "bear skin" );
   set_gettable( 1 );
   set_droppable( 1 );
   set_height( 5 );
   set_weight( 2000 );
   set_bulk( 1800 );
   set_value( 70 );
/* } OBJEDIT */
}
mapping query_aspects() {
   return ([ C_PELT, C_BEARSKIN ]);
}
