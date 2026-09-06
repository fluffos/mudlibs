inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

TASTE( "It tastes like it smells." )

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a blacksmith's shop" );
   set_specific( "the blacksmith's shop" );
   set_look( "This is a blacksmith made of mostly wood and stone. There is a chimney for the forge in the rear." );
   set_plural( "blacksmith's shops" );
   set_name( "smithshop" );
   set_alt_name( ({ "smith", "smith's shop", "blacksmith" }) );
   set_type( "building" );
   set_phrase( "A sturdy wood and stone blacksmith has been built here." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_row( query_x()+1, query_y(), "___", 0x80, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1,"|   |\n|___|\n|_ _|", 0x70, LAYER_WALL);
   painter->paint_row( query_x()+2, query_y()+1,"##", 0x73, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 5, 4 );
}

void on_build() {
   object start_room, door;
//   int ix, iy;

   ROOM_MAP( 4, 4, 1,
   "aaaa"
   "a..a"
   "aaaa"
   "aaaa" )
   ROOM_KEY( "a", "start", "Inside the blacksmith", "This is a blacksmith shop, suitable for forging metals." )

   door = clone_object("/world/exit/door");
   door->move( environment() );
   door->set_host( this_object() );
   door->set_coord( MAKE_C(2,3,0) );
   door->set_dir( "house" );
   door->set_link( "start" );
   door->query_backlink()->set_coord( MAKE_C(10,13,0) );
}
