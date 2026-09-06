inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bjorn/bjorn_lynne-winding_roads" )

TASTE( "It tastes like a bargain." )
DISTANT( "a market" )
SPECIFIC( "the market" )
LOOK( "The market is a covered area with several stalls inside.\n\nThis market belongs to $(OWNER)" )
PLURAL( "markets" )
NAME( "market" )
PHRASE( "Cries of shopkeepers hawking their wares are heard from inside a covered market ~plac." )

create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()+1, query_y(), "___\t\t\t___\n\t\t\t\t_", 0x8b, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "/___\\\t/___\\\n/___\\_/___\\", 0x0b, LAYER_WALL );
   painter->paint( query_x(), query_y()+3, '/', 0x7b, LAYER_WALL );
   painter->paint( query_x()+10, query_y()+3, '\\', 0x7b, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+3, "\t ....... \n|\t_\t_._\t_\t|", 0x70, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+4, "#\t#\t\t\t#\t#", 0x73, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 11, 5 );
}

void on_build() {
   object *rooms, counter, gate, shopkeeper;
   int i;

   ROOM_MAP( 9, 3, 1,
   "dddeeefff"
   "aaabbbccc"
   "aaabbbccc" )
   ROOM_KEY( "a", "west_stall", "Market stall", "A stall selling goods." )
   ROOM_KEY( "b", "mid_stall", "Market stall", "A stall selling goods." )
   ROOM_KEY( "c", "east_stall", "Market stall", "A stall selling goods." )
   ROOM_KEY( "d", "west_back", "The shop's back room", "A storage area behind the stall." )
   ROOM_KEY( "e", "mid_back", "The shop's back room", "A storage area behind the stall." )
   ROOM_KEY( "f", "east_back", "The shop's back room", "A storage area behind the stall." )

   rooms = ({ present("west_stall", this_object()),
      present("mid_stall", this_object()),
      present("east_stall", this_object()) });

   make_outside_exit( rooms[1], MAKE_C(5,4,0) );
   link_rooms( "west_stall", "mid_stall", MAKE_C(16,5,0), "east" );
   link_rooms( "mid_stall", "east_stall", MAKE_C(16,5,0), "east" );

   link_rooms( "west_stall", "west_back", MAKE_C(4,0,0), "north" );
   link_rooms( "mid_stall", "mid_back", MAKE_C(8,0,0), "north" );
   link_rooms( "east_stall", "east_back", MAKE_C(12,0,0), "north" );

   link_rooms( "west_back", "mid_back", MAKE_C(16,2,0), "east" );
   link_rooms( "mid_back", "east_back", MAKE_C(16,2,0), "east" );

   for( i = 0; i < 3; i++ ) {
      counter = clone_object("/scn/furni/counter");
      counter->move( rooms[i] );
      gate = clone_object("/scn/furni/gate");
      gate->move( rooms[i] );

      switch(i) {
         case 0:
         case 2:
            counter->set_coord( MAKE_C(8,1,0) );
            counter->set_direction( 1 );
            counter->set_length( 5 );
            gate->set_coord( MAKE_C(8,6,0) );
            break;
         case 1:
            counter->set_coord( MAKE_C(1,4,0) );
            counter->set_direction( 0 );
            counter->set_length( 14 );
            gate->set_coord( MAKE_C(15,4,0) );
            break;
      }
   }
}
