#include <object.h>
#include <saveload.h>
#include <desc.h>
#include <scenedesc.h>
#include <blocker.h>

/** This is the door object.
 */

/// This flag is set to true if this door is closed, false if it's open.
int closed;

/// Constructor for the door object.
create() {
/* OBJEDIT { */
   set_distant( "a door" );
   set_specific( "the door" );
   set_look( "You a see a door to your ~dirc." );
   set_plural( "doors" );
   set_name( "door" );
   set_phrase( "There is a door ~plac." );
   set_position( "to the ~dirc" );
   set_block_message( "You can't go that way!" );
   set_block_visible( 1 );
   set_pass_message( "You go through the door to the ~dirc." );
/* } OBJEDIT */
}

/** A modified id() function, that complements in the one in Desc.
 * This one allows you to differentiate between an "east door",
 * a "west door", etc. Simul_efun::set_direction must be called
 * first, so that the door can know on which wall it is (this
 * is handled by the verb LookV).
 */
object id( string str ) {
   string dir, a, b;

   dir = query_direction();
   if( dir == str ) return this_object();
   if( sscanf( str, "%s" + dir + " %s", a, b ) == 2 )
      str = a + b;

   return ::id( str );
}

/// \return The value of the closed flag.
int query_closed() { return closed; }

/// An alias for query_closed. Use the door as a variable blocker.
int query_blocked() { return closed; }

/// Sets the value of the closed flag to \a x.
void set_closed( int x ) { closed = x; }
