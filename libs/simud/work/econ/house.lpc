inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

TASTE( "~Pron can never really go home again, you know." )

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a house" );
   set_specific( "the house" );
   set_look( "This is a house made of mostly wood and stone.  Eventually, you will be able to see the owner's name here." );
   set_plural( "houses" );
   set_name( "house" );
   set_alt_name( ({ "home" }) );
   set_type( "home" );
   set_phrase( "A newly built house stands here.  It has one dirt floor, and its windows are made of wooden shutters over a hole in the side." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_row( query_x()+1, query_y(), "_______", 0x80, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1,"|       |\n|_______|\n|       |\n|       |\n|_______|", 0x70, LAYER_WALL);
   painter->paint_row( query_x()+2, query_y()+1,"##", 0x73, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 9, 6 );
}

void on_build() {
   object start_room, door, bedroom;
//   int ix, iy;

   ROOM_MAP( 14, 9, 1,
   "cccccccccccccc"
   "cccccccccccccc"
   "cccccccccccccc"
   "aaaaaaaaabbbbb"
   "aaaaaaaaabbbbb"
   "aaaaaaaaabbbbb"
   "aaaaaaaaabbbbb"
   "aaaaaaaaabbbbb"
   "aaaa.aaaabbbbb")
   ROOM_KEY( "a", "livingroom", "The 'living room'", "Welcome to our house!" )
   ROOM_KEY( "b", "parlor", "The parlor", "A room with which to spend one's free time." )
   ROOM_KEY( "c", "bedroom", "The bedroom", "A room with which to sleep." )

   start_room = find_room("livingroom", this_object());
   bedroom = find_room("bedroom", this_object());

   door = clone_object("/world/exit/door");
   door->move( environment() );
   door->set_host( this_object() );
   door->set_coord( MAKE_C(5,5,0) );
   door->set_dir( "house" );
   door->set_link( "livingroom" );
   door->query_backlink()->set_coord( MAKE_C(23,16,0) );

   door = clone_object("/world/exit/door");
   door->move( start_room );
   door->set_coord( MAKE_C(23,0,0) );
   door->set_dir( "north" );
   door->set_link( "bedroom" );
   door->query_backlink()->set_coord( MAKE_C(17,10,0) );

   door = clone_object("/world/exit/door");
   door->move( start_room );
   door->set_coord( MAKE_C(46,10,0) );
   door->set_dir( "east" );
   door->set_link( "parlor" );
   door->query_backlink()->set_coord( MAKE_C(0,10,0) );

   door = clone_object("/world/exit/door");
   door->move( bedroom );
   door->set_coord( MAKE_C(53,10,0) );
   door->set_dir( "southeast" );
   door->set_link( "parlor" );
   door->query_backlink()->set_coord( MAKE_C(5,0,0) );
}
