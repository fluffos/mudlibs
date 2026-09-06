inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

TASTE( "That's the sound of inevitability." )

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a shop" );
   set_specific( "the shop" );
   set_look( "A small shop." );
   set_plural( "shops" );
   set_name( "shop" );
   set_alt_name( ({ "store" }) );
   set_phrase( "A small shop has been set up ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_row( query_x()+1, query_y(), "___", 0x80, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "|_\t_|\n||.||", 0x70, LAYER_WALL );
   painter->paint( query_x()+2, query_y()+1, 'o', 0x79, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 5, 3 );
}

void on_build() {
   object start_room, door, counter, gate;

   ROOM_MAP( 3, 3, 1,
   "abb"
   "aaa"
   "aaa" )
   ROOM_KEY( "a", "start", "Inside the shop", "This is a small shop. It's handy for commerce." )
   ROOM_KEY( "b", "backroom", "The shop's back room", "A small room in the back of the shop. The shopkeeper can spend the night here." )

   start_room = find_room("start", this_object());

   door = clone_object("/world/exit/door");
   door->move( environment() );
   door->set_host( this_object() );
   door->set_coord( MAKE_C(2,2,0) );
   door->set_dir( "shop" );
   door->set_link( "start" );
   door->query_backlink()->set_coord( MAKE_C(8,10,0) );

   door = clone_object("/world/exit/door");
   door->move( start_room );
   door->set_coord( MAKE_C(8,3,0) );
   door->set_dir( "north" );
   door->set_link( "backroom" );
   door->query_backlink()->set_coord( MAKE_C(3,4,0) );

   counter = clone_object("/scn/furni/counter");
   counter->move( start_room );
   counter->set_coord( MAKE_C(1,6,0) );
   counter->set_direction( 0 );
   counter->set_length( 14 );

   gate = clone_object("/scn/furni/gate");
   gate->move( start_room );
   gate->set_coord( MAKE_C(15,6,0) );
}
