inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bjorn/bjorn_lynne-under_the_bards_tree" )
LOOK( "This is a wood shack, small but cozy.\n\nOwned by $(OWNER)." )

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a shack" );
   set_specific( "the shack" );
   set_plural( "shacks" );
   set_name( "shack" );
   set_type( "home" );
   set_phrase( "A small shack stands ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "/##\\", 48, LAYER_WALL );
   painter->paint_row( query_x(), query_y()+1,   "|_.|", 48, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 4, 2 );
}

void on_build() {
   object start_room;

   ROOM_MAP( 2, 2, 1,
   "aa"
   "aa")
   ROOM_KEY( "a", "shack", "The shack's sole room", "The room is a bit cramped, but liveable." )

   start_room = find_room("shack", this_object());

   make_outside_exit( start_room, MAKE_C(2,1,0) );
}
