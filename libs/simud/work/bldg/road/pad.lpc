inherit "/bldg/wall/wall";
#include <shape.h>

NAME( "pad" )
DISTANT( 0 )
SPECIFIC( "the pad" )
PLURAL( "pads" )
LOOK( "It's a pad on the ground. It has seams around the edge, suggesting it might depress if stepped upon." )
PHRASE( 0 )

int color;
symbol trigger_object;
// Note: The reason I am not using a closure for this is that I
// want the trigger_function & trigger_value variables to survive
// a mud reboot! Closures cannot do this. This is obviously less
// flexible than a closure, but hopefully will do the job. It's
// also a bit easier to understand than closures if you're a
// beginner...
string trigger_function;
mixed trigger_value;

void set_color( int x ){
   color = x;
}

int query_color() {
   return color;
}

int query_tile_width() {
   return 1;
}

int query_tile_height() {
   return 1;
}

void set_trigger_object( object ob ) {
   trigger_object = to_objectref(ob);
}

object query_trigger_object() {
   return find_objectref( trigger_object );
}

void set_trigger_function( mixed x ) {
   trigger_function = x;
}

string query_trigger_function() {
   return trigger_function;
}

void set_trigger_value( mixed x ) {
   trigger_value = x;
}

string query_trigger_value() {
   return trigger_value;
}

void on_map_paint( object painter ) {
   int point, ix, iy;
   mapping spots;

   spots = query_spots();

   foreach( point : spots ) {
      if( CX(point) > environment()->query_map_xdim() ||
         CY(point) > environment()->query_map_ydim() ) {
         remove_spot(point);
         continue;
      }

      painter->paint( CX(point), CY(point), '*', query_color(), LAYER_TERRAIN );
   }
}

int on_walk( object actor, int start, int end ) {
   object ob;

   if( actor->query_is_living() && member(query_spots(), end) && !member(query_spots(), start) ) {
      actor->msg_local("~CACTAs ~name ~verbstep on the pad, it sinks slightly into the ground, and a faint clicking sound is heard.~CDEF");
      if( ob = query_trigger_object() ) {
         call_other( ob, trigger_function, trigger_value );
         return 1;
      }
   }
   return 0;
}
