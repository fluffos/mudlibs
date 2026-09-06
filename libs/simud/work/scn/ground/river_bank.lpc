#include <const.h>
#include <inven.h>
#include <desc.h>
#include <object.h>
#include <landscape.h>
#include <scenedesc.h>

int query_tile_num() { return 15; }

// How much more eating you can get from this grass.
int condition;

int query_fertile() { return 10; }

LOOK("The bank consists of slippery, damp soil.")
DISTANT( "a river bank" )
SPECIFIC( "the river bank" )
NAME( "river bank" )
PHRASE( "At the water's edge, the soil is dark and rich." )
ALT_NAME( ({ "bank" }) )
PLURAL( "river banks" )

int on_dig( int delta ) {
   if( delta ) return 0; // Doesn't apply

   if( random(4) == 0 ) {
      this_player()->msg_local( "~CACT~Name ~verbdig through the soil of the river bank and ~verbturn up a piece of flint!~CDEF" );
      clone_object( "/econ/raw/flint")->move(this_player());
      return 1;
   }
   this_player()->msg_local( "~CACT~Name ~verbdig through the soil of the river bank, but ~verbget nothing but muddy hands for ~poss troubles.~CDEF" );
   return 1;
}
