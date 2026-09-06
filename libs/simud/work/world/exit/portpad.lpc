inherit "/world/exit/exit";
#include <desc.h>
#include <spots.h>
#include <shape.h>

DISTANT( 0 )
LOOK("This pad is made from stone and almost perfectly smooth. A pattern of smooth, waving lines is etched on the surface." )
SPECIFIC( "the teleport pad" )
PLURAL( "teleport pads" )
ALT_NAME( ({ "pad", "teleport pad", "portpad" }) )
ALT_PLURAL( ({ "pads" }) )

/** A device used for building puzzles or triggered systems.
 */

/// See set_mode() for possible values.
string mode;
int dest_coord;

object id( string x ) {
   object ob;
   ob = exit::id(x);
   if( ob ) return ob;
   ob = desc::id(x);
   if( ob ) return ob;
   return 0;
}

/** Mode can currently be any of the following:
 * "on" -- Always active. This is the default.
 * "off" -- Never active
 * "sequence" -- Activates for a single teleport if triggered in a
 *    certain sequence. Gives a message when the sequence is completed.
 *    You have to use set_var("sequence_length") to give the length of
 *    the sequence -- if it's zero, it will always be on.
 *
 * It should be fairly easy to add more modes as need dictates.
 */
void set_mode( string x ) {
   mode = x;
}

void set_dest_coord( int x ) {
   dest_coord = x;
}

int query_dest_coord() {
   return dest_coord;
}

string query_mode() {
   return mode;
}

void on_sequence( int which ) {
   if( query_var("sequence_count") == which - 1 )
      set_var( "sequence_count", which );
   else {
      set_var( "sequence_count", 0 );
      if( query_var("sequence_break_message") )
         msg_room( environment(), query_var("sequence_break_message") );
      return;
   }

   if( query_var("sequence_count") < query_var("sequence_length") &&
      query_var("sequence_message") &&
      environment() )
      msg_room( environment(), query_var("sequence_message") );
   else if( query_var("sequence_count") >= query_var("sequence_length") &&
      query_var("sequence_finish_message") &&
      environment() )
      msg_room( environment(), query_var("sequence_finish_message") );
}

int query_active() {
   switch( mode ) {
      default        : return 1; // "on"
      case "off"     : return 0;
      case "sequence": return query_var("sequence_count") >= query_var("sequence_length");
   }
}

string query_look() {
   string s;

   s = ::query_look();
   if( s ) s = s + " ";
   else s = "";
   if( query_active() )
      return s + "The pad is glowing brightly! The air above it seems to curl and sizzle menacingly.";
   else
      return s + "Currently, the pad is dark and silent.";
}

void on_paint( object painter ) {
   int point, ix, iy;
   mapping sp;

   sp = query_spots();

   foreach( point : sp ) {
      if( CX(point) > environment()->query_map_xdim() ||
         CY(point) > environment()->query_map_ydim() ) {
         remove_spot(point);
         continue;
      }

      painter->paint( CX(point), CY(point), '*', query_active()?11:8, LAYER_TERRAIN );
   }
}

int on_walk( object actor, int start, int end ) {
   object ob;

   if( actor->query_is_living() && member(query_spots(), end) && !member(query_spots(), start) ) {
      exit_action();
      return 1;
   }
   return 0;
}

int exit_action() {
   object dest;

   if( !member(query_spots(), this_player()->query_coord()) ) {
      msg("To go that way, you must walk onto the pad.");
      return 0;
   }
   else if( !query_active() ) {
      msg("The pad is inactive.");
      return 0;
   }

   dest = get_destination( link );
   if( !dest ) {
      msg( "That exit doesn't seem to lead anywhere!");
      debug(object_name(this_object()) + " complains: I'm an unlinked exit.");
      return 0;
   }
   this_player()->move_player( dest, "teleport" );
   if( dest_coord ) this_player()->set_coord( dest_coord );

   if( this_player()->query_is_player() || this_player()->query_possessor() )
      "/bin/look"->main();

   return 1;
}


int query_is_exit() {
   return query_active();
}
