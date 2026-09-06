#include <desc.h>
#include <scenedesc.h>
#include <object.h>
#include <shape.h>
#include <coord.h>
#include <spots.h>
#include <saveload.h>

NAME( "snowdrift" )
DISTANT( "a snowdrift" )
SPECIFIC( "the snowdrift" )
ALT_NAME( ({ "drift", "snow" }) )
PHRASE( sizeof(query_spots())? "Snow is covering the ground thickly here." : "The snow has all been cleared away." )

mapping default_spots = ([ ]);

mapping query_default_spots() {
   return default_spots;
}

mapping set_default_spots( mapping x ) {
   if( mappingp(x) ) default_spots = x;
}

void on_map_paint( object painter ) {
   int ipos;

   foreach( ipos : query_spots() ) {
      painter->paint( query_x() + CX(ipos),
         query_y() + CY(ipos),
         '#',
         0x7F,
         LAYER_WALL );
   }
}

void add_spot( int pos ) {
   ::add_spot( pos );
   set_default_spots( copy(query_spots()) );
}

void remove_spot( int pos ) {
   ::remove_spot( pos );
   set_default_spots( copy(query_spots()) );
}

string destructor( object ob ) {
   if( environment() ) environment()->clear_map();
   return ::destructor(ob);
}

int query_is_diggable() {
   return 1;
}

string query_action_name() {
   return "Shovel";
}

string query_look() {
   return "The heavy snow is piled up so deep and thick that digging through would be difficult.";
}

/// Dig in the direction given in \a param, offsetting the player.
int on_dig( int param ) {
   int i, pos;

   if( !param ) return 0; // Doesn't apply

   pos = OFFSET_C(this_player()->query_coord(), param);

   if( !query_has_spot(pos) ) {
      msg("Digging that direction didn't work.");
      return 0; // Action disappears if you moved.
   }

   this_player()->set_coord(pos);
   ::remove_spot(pos);
   environment(this_player())->clear_map();
   this_player()->msg_local("~CACT~Name ~verbdig into the snow.~CDEF");
   this_player()->add_readiness( -500 );

   return 1;
}

void reset() {
   int imissing;

   ::reset();
   foreach( imissing : query_default_spots() - query_spots() ) {
      if( random(3) == 0 ) {
         ::add_spot( imissing );
         return;
      }
   }
   if( environment() ) environment()->clear_map();
}
