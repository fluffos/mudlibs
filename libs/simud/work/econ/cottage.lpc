inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

TASTE( "It tastes like the Swedish Alps." )

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a cottage" );
   set_specific( "the cottage" );
   set_look( "This is a quaint cottage with a red terracotta roof." );
   set_plural( "cottages" );
   set_name( "cottage" );
   set_type( "home" );
   set_phrase( "A small cottage with a red roof has been built ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_row( query_x()+1, query_y(), "___", 0x89, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "/%%%\\", 0x09, LAYER_WALL );
//   painter->paint_row( query_x()+1, query_y()+1, "___", 0x19, LAYER_WALL);
   painter->paint_row( query_x(), query_y()+2, "|_._|", 0x78, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 5, 3 );
}

void on_build() {
   object start_room, door;
//   int ix, iy;

   ROOM_MAP( 3, 3, 1,
   "bbb"
   "aaa"
   "aaa")
   ROOM_KEY( "a", "start", "The cottage's front room", "This small front room is cramped but cozy." )
   ROOM_KEY( "b", "backroom", "The back room", "A small space at the back of the cottage." )

   start_room = find_room("start", this_object());

   door = clone_object("/world/exit/door");
   door->move( environment() );
   door->set_host( this_object() );
   door->set_coord( MAKE_C(2,2,0) );
   door->set_dir( "cottage" );
   door->set_link( "start" );
   door->query_backlink()->set_coord( MAKE_C(8,7,0) );

   door = clone_object("/world/exit/door");
   door->move( start_room );
   door->set_coord( MAKE_C(8,0,0) );
   door->set_dir( "north" );
   door->set_link( "backroom" );
   door->query_backlink()->set_coord( MAKE_C(8,4,0) );
}
