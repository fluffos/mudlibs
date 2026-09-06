#include <object.h>
#include <inven.h>
#include <const.h>

string dir, link;

string query_dir();

string query_name() {
   return "exit_" + query_dir();
}

object id( string x ) {
   return ( x == query_name() || x == query_dir() ) ? this_object() : 0;
   //return ( x == query_name() ) ? this_object() : 0;
}

string query_link() {
   return link;
}

void set_link( string x ) {
   link = x;
}

string query_dir() {
   return dir;
}

void set_dir( string x ) {
   dir = x;
}

mapping query_aspects() {
   return ([ C_EXIT ]);
}

varargs object get_destination( string dest ) {
   object ob;

   if( !dest ) dest = link;
   if( !dest ) return 0;
   if( !environment(this_object()) ) return 0;
   if( ob = this_object()->query_host() )
      return find_room( dest, ob );
   else
      return find_room( dest, environment(environment(this_object())) );
}

int exit_action() {
   object dest;

   dest = get_destination( link );
   if( !dest ) {
      msg( "That exit doesn't seem to lead anywhere!");
      debug(object_name(this_object()) + " complains: I'm an unlinked exit.");
      return 0;
   }
   if( this_player()->query_stance() != ST_STANDING )
      "/bin/stand"->main();
   if( query_dir() ) {
      this_player()->move_player( dest, this_player()->query_movement_type(), query_dir() );
   }
   else
      this_player()->move_player( dest );

   // Don't waste time on room descs for NPC's, unless they're possessed.
   if( this_player()->query_is_player() || this_player()->query_possessor() )
      "/bin/look"->main();

   return 1;
}

int query_is_exit() {
   return 1;
}

int exit_verb( string param ) {
   if( query_verb() != query_dir() && query_verb() + " " + param != query_dir() )
      return 0;
   return "/bin/go"->main( query_dir() );
}

mapping query_hotspots() {
   return this_object()->exit_shape();
}

void on_hotspot( int pos ) {
   exit_action();
}
