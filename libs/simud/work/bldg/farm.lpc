inherit "/econ/building";
#include <const.h>
#include <const/shapeconst.h>
#include <const/roomconst.h>

// Seconds between vegetable spawns
#define SPAWN_FREQUENCY 600

BGM( "bjorn/bjorn_lynne-homeland_farmland" )

DISTANT( "a farmhouse" )
SPECIFIC( "the farmhouse" )
LOOK( "A small, rural farmhouse, built from logs, with a thatched roof.\n\nOwned by $(OWNER)." )
PLURAL( "farmhouses" )
ALT_PLURAL( ({ "houses", "buildings" }) )
NAME( "farmhouse" )
ALT_NAME( ({ "farm", "house", "farm house" }) )
TYPE( "building" )
PHRASE( "A farmhouse stands ~plac." )

void create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "/:::\\", 0x0b, LAYER_WALL );
   painter->paint_row( query_x(), query_y()+1,   "|_._|", 0x70, LAYER_WALL );
}

mapping query_shape() {
   return SHAPE_BOX( 4, 2 );
}

int last_spawn_time;
int kid_spawn_time;

int query_last_spawn_time() {
   return last_spawn_time;
}

int query_kid_spawn_time() {
   return kid_spawn_time;
}

void set_last_spawn_time(int time) {
   last_spawn_time = time;
}

void set_kid_spawn_time(int time) {
   kid_spawn_time = time;
}

object get_work_spot() {
   return present( "work_spot", find_room("start", this_object()) );
}

object get_silo() {
   return present( "veg_silo", find_room("garden", this_object()) );
}

void supply_food() {
   object ob, silo = get_silo();
   if( silo ) {
      foreach( ob : all_inventory(environment()) ) {
         // Easy-out; this isn't perfect, it could be a non-food
         // item or something.
         if( !first_inventory(silo) )
            return;
         ob->on_supply( silo );
      }
   }
}

void spawn_vegetables()
{
   string veg;
   object silo = get_silo();
   // Spawn vegetables at a constant rate in the silo.
   switch( random(7) ) {
      case 0: veg = "carrot"; break;
      case 1: veg = "corn"; break;
      case 2: veg = "lettuce"; break;
      case 3: veg = "onion"; break;
      case 4: veg = "potato"; break;
      case 5: veg = "tomato"; break;
      case 6: veg = "sugar_beet"; break;
   }
   if( veg ) {
      object ob = clone_object( "/econ/crop/" + veg );
      ob->move( silo );
   }
}

void spawn_kid() {
   object kid = clone_object( "/monsters/human" );
   kid->move( find_room("start", this_object()) );
   kid->set_home( this_object() );
   kid->validate_position();
   kid->use_ai_module( "farmer_kid" );
   command( "walk random", kid );
}

void reset()
{
   ::reset();
   object spot = get_work_spot();
   if( !is_clone(this_object()) )
      return;
   if( spot && !spot->query_num_employees() )
      return;
   if( !last_spawn_time )
      last_spawn_time = time();
   while( last_spawn_time < time() ) {
      spawn_vegetables();
      last_spawn_time += SPAWN_FREQUENCY;
      kid_spawn_time++;
   }
   // It takes about 1,000,000 seconds for a kid to grow up,
   // so to keep the rate reasonable, I want it to take about
   // a third that for them to spawn. 500 * 600 = 300,000.
   while( kid_spawn_time >= 500 ) {
      debug("Producing a kid", "gp");
      spawn_kid();
      kid_spawn_time -= 500;
   }
   // Spread out any food we have, although only if we have
   // employees.
   supply_food();
}

void on_build() {
   object start_room, spawn;

   ROOM_MAP( 3, 4, 1,
   "ccc"
   "ccc"
   "aab"
   "aab")
   ROOM_KEY( "a", "start", "The Main Room", "This is the farmhouse's cozy living area." )
   ROOM_KEY( "b", "pantry", "The Pantry", "A small side room where food is stored." )
   ROOM_KEY( "c", "garden", "The Garden", "Behind the farmhouse is a small vegetable garden." )

   start_room = find_room("start", this_object());

   object silo = clone_object( "/scn/furni/veg_silo" );
   silo->move( find_room("garden", this_object()) );
   silo->set_coord( MAKE_C(1,1,0) );

   make_outside_exit( start_room, MAKE_C(2,1,0) );
   link_rooms( "start", "pantry", MAKE_C(11,3,0), "east" );
   link_rooms( "pantry", "garden", MAKE_C(3,0,0), "north" );

   object ob;
   ob = clone_object( "/scn/furni/larder" );
   ob->move( find_room("pantry", this_object()) );
   ob->set_x(2); ob->set_y(6);
   set_larder( ob );

   spawn = clone_object( "/obj/work_spot" );
   spawn->move( start_room );
   spawn->set_work_name( "farmer" );
   spawn->set_work_ai( "farmer" );
   spawn->set_home( this_object() );
   spawn->set_num_positions( 1 );
   spawn->set_coord( MAKE_C(5,3,0) );
}
