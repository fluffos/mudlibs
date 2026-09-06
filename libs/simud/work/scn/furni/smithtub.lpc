#include <container.h>
#include <scenedesc.h>
#include <desc.h>
#include <shape.h>
#include <coord.h>
#include <object.h>
#include <inven.h>

ALT_NAME( ({"metal tub","tub"}) )
NAME( "smithtub" )
DISTANT( "a metal tub" )
SPECIFIC( "the metal tub" )
LOOK( "It's a beat up, metal tub. It has scorch marks along the sides, and many dents." )
PLURAL( "tubs" )
ALT_PLURAL( ({"metal tubs"}) )
PHRASE( "There is a beat up metal smith's tub here." )
TASTE( "It tastes like Grandma." )
GETTABLE( 0 )
DROPPABLE( 1 )

void on_pour_into( object who,int amount ) {
   object ob;
   if ( ob = single_present("blacksmith",environment(this_object())))
      ob->add_water( who,amount );
}

void create() {
   ::create();
   set_weight_capacity( 800000 );
   set_bulk_capacity( 1600000 );
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "\t__\n(", 0x87, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+1, "__", 0x47, LAYER_WALL );
   painter->paint_shape( query_x()+3, query_y()+1, ")", 0x87, LAYER_WALL );
}
