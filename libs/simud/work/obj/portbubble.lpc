#include <inven.h>
#include <desc.h>
#include <object.h>

// Defaults to invisible
NAME( "portbubble" )
LOOK( 0 )
DISTANT( 0 )
SHORT( "The plane of wind" )
LONG( "The plane of wind whizzes by as you travel elsewhere..." )

int duration;
string arrive_message;

void set_duration( int x ) { duration = x; }
int query_duration() { return duration; }

void create() {
   ::create();
   duration = 3;
   arrive_message = "~CACT~Name ~verbarrive.~CDEF";
}

void init() {
   ::init();
   set_heart_beat( 1 );
}

void set_arrive_message( string x ) {
   arrive_message = x;
}

string query_arrive_message() {
   return arrive_message;
}

void heart_beat() {
   object ob;
   --duration;
   if( duration <= 0 ) {
      foreach( ob : all_inventory() ) {
         set_actor( ob );
         if( ob->query_distant() )
            msg_room( environment(), arrive_message );
         ob->move( environment() );
         ob->validate_position();
      }
      destruct( this_object() );
   }
}

int query_is_port_bubble() {
   return 1;
}
