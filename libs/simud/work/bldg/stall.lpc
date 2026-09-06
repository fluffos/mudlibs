inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bjorn/bjorn_lynne-winding_roads" )

TASTE( "That's the sound of inevitability." )

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a stall" );
   set_specific( "the stall" );
   set_look( "A small merchant's stall." );
   set_plural( "stalls" );
   set_name( "stall" );
   set_phrase( "A small covered stall has been set up ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

/**
 * ,_,
 * |.|
 */

void on_map_paint( object painter ) {
	painter->paint_shape( query_x(), query_y(), ",_,\n|.|",0x88, LAYER_WALL);
	painter->paint_shape( query_x(), query_y(), ",\t,",0x8A, LAYER_WALL);
}

mapping query_shape() {
   return SHAPE_BOX( 3, 2 );
}

void on_build() {
   object start_room, door, counter, gate, shopkeeper;

   ROOM_MAP( 1, 1, 1, "a" )
   ROOM_KEY( "a", "start", "Inside the stall", "This is an incredibly cramped shop with little room to hold even the wares being sold - much less the merchant and yourself." )

   start_room = find_room("start", this_object());

   door = clone_object("/world/exit/door");
   door->move( environment() );
   door->set_host( this_object() );
   door->set_coord( MAKE_C(1,1,0) );
   door->set_dir( "stall" );
   door->set_link( "start" );
   door->query_backlink()->set_coord( MAKE_C(4,4,0) );

   counter = clone_object("/scn/furni/counter");
   counter->move( start_room );
   counter->set_coord( MAKE_C(1,2,0) );
   counter->set_direction( 0 );
   counter->set_length( 4 );

   shopkeeper = clone_object( "/monsters/shopkeeper" );
   shopkeeper->move( start_room );
   shopkeeper->set_coord( MAKE_C(2,1,0) );

   gate = clone_object("/scn/furni/gate");
   gate->move( start_room );
   gate->set_coord( MAKE_C(5,2,0) );
}
