// A temp object used to spawn monsters at a given
// point. Only spawns when no creatures are around.

#include <object.h>
#include <saveload.h>
#include <spots.h>

#define SPAWN_DELAY 1800

string type;

string query_type();

void create() {
   ::create();
   call_out("spawn_tick", SPAWN_DELAY+random(SPAWN_DELAY));
   type = "!peasant";
}

string query_name() {
   return "_peasant_spawn";
}

object id( string s ) {
   if( s == "_peasant_spawn" ) return this_object();
}

void spawn_tick() {
   object ob;

   if( !environment() ) return;
   remove_call_out("spawn_tick");
   call_out( "spawn_tick", SPAWN_DELAY + random(SPAWN_DELAY) );

   ob = clone_object( "/monsters/human" );
   ob->move( environment() );
   if( !ob ) return;

   ob->use_ai_module("farmer_kid");

   if( !sizeof(query_spots()) )
      ob->set_coord( MAKE_C(random(environment()->query_map_xdim()/5)*5+3, random(environment()->query_map_ydim()/3)*3+2, 0) );
   else
      ob->set_coord( m_indices(query_spots())[random(sizeof(query_spots()))] );
}

void set_type( string s ) {
   type = s;
}

string query_type() {
   return type;
}
