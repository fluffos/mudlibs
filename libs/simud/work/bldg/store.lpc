inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bjorn/bjorn_lynne-winding_roads" )

TASTE( "It has a distinct flavor of commercialism." )
LOOK( "A big store.?(HASSIGN: Written on the store's sign is: '$(SIGNDESC)'\n\nOwned by $(OWNER).) ")

string sign_text;
string sign_desc;

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a store" );
   set_specific( "the store" );
   set_plural( "stores" );
   set_name( "store" );
   set_alt_name( ({ "store", "store", "store" }) );
   set_phrase( "A big store has been set up ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
   sign_text = "";
   sign_desc = "";
}


void set_sign( string x ) {
   sign_text = x;
   if( environment() ) environment()->clear_map();
}

void set_sign_desc( string x ) {
   sign_desc = x;
}

string query_sign() {
   return sign_text;
}

string query_sign_desc() {
   return sign_desc;
}

int query_has_sign() {
   return 1;
}

void on_map_paint( object painter ) {
   painter->paint_row( query_x()+1, query_y(), "_______", 0x89, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+1, "///|||\\\\\\", 0x09, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2, "|       |\n|[]_._[]|", 0x70, LAYER_WALL );
   if( stringp(sign_text) )
   painter->paint_row( query_x()+4 - strlen(sign_text)/2, query_y()+2, sign_text, 0x30, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 9, 4 );
}

void on_build() {
   object start_room, counter, gate, shopkeeper;

   ROOM_MAP( 5, 4, 1,
   "bbbbb"
   "abbba"
   "aaaaa"
   ".aaa." )
   ROOM_KEY( "a", "start", "Inside the store", "This is a large, spacious store." )
   ROOM_KEY( "b", "backroom", "The store's back room", "A big storage area." )

   start_room = find_room("start", this_object());

   make_outside_exit( start_room, MAKE_C(4,3,0) );
   link_rooms( "start", "backroom", MAKE_C(13,3,0), "north" );

   counter = clone_object("/scn/furni/counter");
   counter->move( start_room );
   counter->set_coord( MAKE_C(6,7,0) );
   counter->set_direction( 0 );
   counter->set_length( 14 );

   shopkeeper = clone_object( "/monsters/shopkeeper" );
   shopkeeper->move( start_room );
   shopkeeper->set_coord( MAKE_C(13,6,0) );

   gate = clone_object("/scn/furni/gate");
   gate->move( start_room );
   gate->set_coord( MAKE_C(20,7,0) );
}
