inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

DISTANT( "a barracks" )
SPECIFIC( "the barracks" )
LOOK( "It's a sturdy stone building with very small windows." )
PLURAL( "barracks" )
NAME( "barracks" )
TYPE( "building" )
PHRASE( "The presence of a barracks adds a feeling of security to the area." )

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()+1, query_y(), "__\t\t__", 0x89, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "/_/\\/_/\\", 0x09, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "| |_| ||\n|__.__||", 0x78, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 8, 4 );
}

void on_build() {
   object start_room, door;

   ROOM_MAP( 9, 3, 2,
   "........."
   "aaa...bbb"
   "aaa...bbb"
   "dddd.eeee"
   "dddccceee"
   "ddd...eee")
   ROOM_KEY( "a", "left_tower", "Left tower of the barracks", "A small tower with a stone floor and narrow portcullis windows." )
   ROOM_KEY( "b", "right_tower", "Right tower of the barracks", "A small tower with a stone floor and narrow portcullis windows." )
   ROOM_KEY( "c", "start", "Entry hallway", "A tight, stone room with narrow doors to the east and west which lead into the rest of the barracks." )
   ROOM_KEY( "d", "sleeping_quarters", "Sleeping quarters", "A musty but tidy room where the guards can catch a few winks between patrols." )
   ROOM_KEY( "e", "office", "Administrative offices", "Spartan furniture marks this area of the barracks. This is where the paperwork gets done." )

   link_rooms( "start", "sleeping_quarters", MAKE_C(0,2,0), "west" );
   link_rooms( "start", "office", MAKE_C(16,2,0), "east" );
   make_outside_exit(  find_room("start",this_object()), MAKE_C(3,3,0) );
   make_stairs( "sleeping_quarters", "left_tower", MAKE_C(8,6,0) );
   make_stairs( "office", "right_tower", MAKE_C(13,6,0) );

   // Default/required furniture.
   object ob;
   ob = clone_object( "/scn/furni/larder" );
   ob->move( find_room("sleeping_quarters", this_object()) );
   ob->set_x( 1 ); ob->set_y( 9 );
   set_larder( ob );

   start_room = find_room("start", this_object());

   object spawn = clone_object( "/obj/work_spot" );
   spawn->move( start_room );
   spawn->set_work_name( "guard" );
   spawn->set_work_ai( "guard" );
   spawn->set_home( this_object() );
   spawn->set_num_positions( 6 );
   spawn->set_coord( MAKE_C(8,2,0) );
}
