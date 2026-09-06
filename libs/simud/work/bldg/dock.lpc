inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bgm/sailors_hornpipe.mid" )

string dock_name, facing;

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a dock house" );
   set_specific( "the dock house" );
   set_look( "Ships dock at this dock house on occasion." );
   set_plural( "dock houses" );
   set_name( "dock" );
   set_alt_name( ({ "dock house" }) );
   set_phrase( "A small dock welcomes incoming ships." );
/* } OBJEDIT */
}

string query_dock_name() {
   if( !dock_name ) return environment(environment())->query_short();
   return dock_name;
}

void set_dock_name( string x ) {
   dock_name = x;
}

void set_facing( string x ) {
   facing = x;
}

string query_facing() {
   if( !facing ) facing = "south"; // Code for update, scratch later.
   return facing;
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x()+1, query_y(), "__", 0x89, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "/__\\", 0x19, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "|__|", 0x7F, LAYER_WALL );

   switch( query_facing() ) {
      case "south":
         painter->paint_shape( query_x()+4, query_y()+1, "|_"+tab("\n|_",5), 0x03, LAYER_WALL );
         break;
      case "north":
         painter->paint_shape( query_x()-2, query_y()-3, "_|"+tab("\n_|",5), 0x03, LAYER_WALL );
         break;
   }
}

mapping query_shape() {
   return SHAPE_BOX( 4, 3 );
}

int query_dock_pos() {
   switch( query_facing() ) {
      case "south":
         return MAKE_C(query_x()-1, query_y()+4, 0);
      case "north":
         return MAKE_C(query_x(), query_y()-3, 0);
   }
   return 0;
}

int query_is_dock() {
   return 1;
}

void msg_ship( object ship, string m ) {
   object front, back;

   front = find_room("front", ship);
   back = find_room("back", ship);

   msg_room( front, m );
   msg_room( back, m );
}

void on_ship_arrive( object ship ) {
   object exit;
   object dockroom, shiproom;

   dockroom = find_room("dock", this_object());
   shiproom = find_room("front", ship);

   exit = clone_object("/world/exit/exit");
   exit->set_dir("ship"); // Set dir before moving to have verb work.
   exit->move(dockroom);
   exit->set_link(get_location(shiproom));

   exit = clone_object("/world/exit/exit");
   exit->set_dir("dock");
   exit->move(shiproom);
   exit->set_link(get_location(dockroom));
   msg_room( dockroom, "~CTITA ship arrives in the dock.~CDEF" );
   msg_ship( ship, "~CTITThe ship pulls in at " + query_dock_name() + ".~CDEF" );
}

void on_ship_depart( object ship ) {
   object exit;
   object dockroom, shiproom;

   dockroom = find_room("dock", this_object());
   shiproom = find_room("front", ship);

   while( exit = present("exit_ship", dockroom) ) destruct( exit );

   while( exit = present("exit_dock", shiproom) ) destruct( exit );

   msg_room( dockroom, "~CTITA ship departs from the dock.~CDEF" );
   msg_ship( ship, "~CTITThe ship pulls away from " + query_dock_name() + ".~CDEF" );
}

void on_build() {
   object start_room;

   ROOM_MAP( 3, 3, 1,
   "aaa"
   "aaa"
   "aaa" )
   ROOM_KEY( "a", "dock", "In the dock", "When a ship is docked, you can board it from here." )

   start_room = find_room("dock", this_object());

   make_outside_exit( start_room, MAKE_C(2,2,0) );
}
