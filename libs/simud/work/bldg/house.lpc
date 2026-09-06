inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bjorn/bjorn_lynne-under_the_bards_tree" )

NAME( "house" )
DISTANT( "a house" )
SPECIFIC( "the house" )
PLURAL( "houses" )
ALT_NAME( ({ "home" }) )
TYPE( "building" )
LOOK( "This is a house made of mostly wood and stone. Posted over the door is a small sign on which is written '$(OWNER)'." )
PHRASE( "A beautifully built stone and wood house stands here." )

create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()+1, query_y(), "\t\t\t___\n__", 0x89, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "\t\t\t/%%%\\\n/%%", 0x09, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2,"\t\t\t| # |\n|_.____|", 0x70, LAYER_WALL);
}

mapping query_shape() {
   return SHAPE_BOX( 8, 4 );
}

void on_build() {
   object start_room;

   ROOM_MAP( 7, 4, 2,
   "......."
   "....ddd"
   "....eed"
   "....eed"
   "ccccfff"
   "ccccbbb"
   "aaaabbb"
   "aaaabbb")
   ROOM_KEY( "a", "livingroom", "Living room", "A spacious, comfortable living room." )
   ROOM_KEY( "b", "parlor", "Parlor", "A room in which to spend one's free time. A staircase leads upward." )
   ROOM_KEY( "c", "bedroom", "Bedroom", "A room in which to sleep." )
   ROOM_KEY( "d", "stairs", "Top of the stairs", "A passageway at the top of the stairs." )
   ROOM_KEY( "e", "study", "Study", "A peaceful room, with windows overlooking the ground below." )
   ROOM_KEY( "f", "passage", "Passage", "A narrow passageway." )

   start_room = find_room("livingroom", this_object());

   make_outside_exit( start_room, MAKE_C(2,3,0) );
   link_rooms( "livingroom", "bedroom", MAKE_C(11,0,0), "north" );
   link_rooms( "livingroom", "parlor", MAKE_C(21,4,0), "east" );
   link_rooms( "bedroom", "passage", MAKE_C(21,2,0), "east" );
   link_rooms( "passage", "parlor", MAKE_C(13,4,0), "south" );
   make_stairs( "parlor", "stairs", MAKE_C(13,8,0) );
   link_rooms( "stairs", "study", MAKE_C(10,5,0), "west" );
}
