#include <const.h>
inherit "/obj/scenery";

DISTANT( "an anvil" )
SPECIFIC( "the avil" )
LOOK( "This is an iron anvil, used for beating metals." )
PLURAL( "anvils" )
NAME( "anvil" )
ALT_NAME( ({ "anvil of falling doom", "iron anvil" }) )
PHRASE( "A iron anvil is standing here." )

void create() {
   ::create();
   set_preposition("inv");
   set_position("here");
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "___", 0x87, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "\\_/", 0x87, LAYER_WALL );
}

mapping query_aspects() {
   return ([C_ANVIL,
            C_METAL ]);
}
