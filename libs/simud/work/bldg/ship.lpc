inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

BGM( "bgm/sailors_hornpipe.mid" )

string *route_list = ({});
int route_number = 0;
object curr_dock;

create() {
   ::create();
/* OBJEDIT { */
   set_distant( "a ship" );
   set_specific( "the ship" );
   set_look( "A proud sailing ship." );
   set_plural( "ships" );
   set_name( "ship" );
   set_alt_name( ({ "sailing ship", "boat" }) );
   set_alt_plural( ({ "sailing ships", "boats" }) );
   set_type( "boat" );
/* } OBJEDIT */

   //route_list += ({ "world;coco2;room_10.54", "world;coco2;room_0.54" });
   if( is_clone(this_object()) ) call_out( "do_route", 1 );
   curr_dock = 0;
}

string *query_route() { return route_list; }

void set_route( string *route_data ) { route_list = route_data; }
void add_route( string *route_data ) { route_list += route_data; }
void delete_route( string *route_data ) { route_list -= route_data; }
void empty_route() { route_list = ({}); }

void do_route() {
   object ob;
   int sw;

   remove_call_out("do_route");

   //debug( "Checking route num vs route size" );
   if( route_number >= sizeof(route_list) ) route_number = 0;

   if( curr_dock ) {
      //debug( "Previous dock found, moving to world" );
      msg_room( environment(), "A small ship sails away." );
      curr_dock->on_ship_depart( this_object() );
      this_object()->move( find_room("world") );
      call_out( "do_route", 60 );
      curr_dock = 0;
      return;
   }

   sw = 0;

   //debug( "Checking route dest for port" );
   if( sizeof(route_list) > 0 )
   foreach( ob : all_inventory(find_room(route_list[route_number])) ) {
      if( ob->query_is_dock() == 1 ) {
         //debug( "Found dock" );
         sw = 1;
         break;
      }
   }
   if( sw == 1 ) {
      //debug( "Switch is good" );
      curr_dock = ob;

      //debug( "Moving ship to dest" );
      this_object()->move( find_room(route_list[route_number]) );
      set_coord( ob->query_dock_pos() );
      ob->on_ship_arrive( this_object() );
      msg_room( environment(), "A small ship sails into view." );

   }
   //debug( "Incrementing, checking" );
   route_number++;
   if( route_number >= sizeof(route_list) ) route_number = 0;
   call_out( "do_route", 50 );
}

void on_map_paint( object painter ) {}

void on_paint( object painter ) {
   painter->paint_shape( query_x(), query_y()+1, "_\t\t\t_", 0x80, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y(), "|_", 0x8F, LAYER_WALL );
   painter->paint_shape( query_x()+1, query_y()+1, ")_)", 0x7F, LAYER_WALL );
   painter->paint_shape( query_x(), query_y()+2,"\\_\t_/", 0x30, LAYER_WALL );
   painter->paint( query_x()+2, query_y()+2, 'o', 0x31, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 5, 3 );
}

void on_build() {
   object front_room, back_room, floor_pattern, exit;

   ROOM_MAP( 3, 6, 1,
   "aaa"
   "aaa"
   "aaa"
   "bbb"
   "bbb"
   "bbb")
   ROOM_KEY( "a", "front", "Bow of the Ship", "This is the front part of the ship." )
   ROOM_KEY( "b", "back", "Stern of the Ship", "This is the back part of the ship." )

   front_room = find_room("front", this_object());
   back_room = find_room("back", this_object());

   floor_pattern = clone_object("/scn/water/ocean");
   floor_pattern->move( front_room );
   floor_pattern = clone_object("/scn/water/ocean");
   floor_pattern->move( back_room );
   floor_pattern = clone_object("/scn/custom_floor");
   floor_pattern->move( front_room );

   floor_pattern->add_pattern(
"\t\t\t\t\t\t . \n"
"\t\t\t\t .   . \n"
"\t\t\t .     . \n"
"\t\t .       . \n"
"\t\t .       . \n"
"\t .         . \n"
"\t .         . \n"
"\t .         . \n", 0x07, MAKE_C(1,2,0), LAYER_BRIDGE );

   floor_pattern->add_pattern(
"\t\t\t\t\t\t.'.\n"
"\t\t\t\t.'\t\t\t'.\n"
"\t\t\t:\t\t\t\t\t\t\t:\n"
"\t\t:\t\t\t\t\t\t\t\t\t:\n"
"\t:\t\t\t\t\t\t\t\t\t\t\t:\n"
".'\t\t\t\t\t\t\t\t\t\t\t'.\n"
":\t\t\t\t\t\t\t\t\t\t\t\t\t:\n"
":\t\t\t\t\t\t\t\t\t\t\t\t\t:\n"
":\t\t\t\t\t\t\t\t\t\t\t\t\t:", 0x3B, MAKE_C(1,1,0), LAYER_WALL );

   floor_pattern->add_pattern( "\t_\n(_)", 0x0B, MAKE_C(7,8,0), LAYER_WALL );

   exit = clone_object("/world/exit/outdoors");
   exit->move( front_room );
   exit->set_link("back");
   exit->set_dir("stern");
   exit = clone_object("/world/exit/outdoors");
   exit->move( back_room );
   exit->set_link("front");
   exit->set_dir("bow");

   floor_pattern = clone_object("/scn/custom_floor");
   floor_pattern->move( back_room );
   floor_pattern->add_pattern( ":\n:\n:\n:\n:\n:", 0x3B, MAKE_C(1,1,0), LAYER_WALL );
   floor_pattern->add_pattern( ":\n:\n:\n:\n:\n:", 0x3B, MAKE_C(15,1,0), LAYER_WALL );
   floor_pattern->add_pattern( "'.\n\t\t'.........'", 0x3B, MAKE_C(1,7,0), LAYER_WALL );
   floor_pattern->add_pattern( ".'", 0x3B, MAKE_C(14,7,0), LAYER_WALL );
   floor_pattern->add_pattern(
" .         . \n"
" .         . \n"
" .         . \n"
" .         . \n"
" .         . \n"
" .         . \n"
"\t  . . . .  ", 0x0f, MAKE_C(2,1,0), LAYER_BRIDGE );

}
