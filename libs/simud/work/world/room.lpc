#include <desc.h>
#include <extra_desc.h>
#include <inven.h>
#include <exits.h>
#include <object.h>
#include <map_paint.h>
#include <const/roomconst.h>

/// \todo Write this summary.

DISTANT( "the ground" )
SPECIFIC( "the ground" )
CAN_BUILD( 0 )
TASTE( "It tastes, well, like dirt." )

int query_can_build() {
   QBODY( "can_build", this_object()->query_default_can_build() );
}

void set_can_build( int x ) {
   SBODY( "can_build", x );
}

/** \return The full description, including scenery, blocker descriptions, etc.
 * NOTE: This function may evaluate some expressions, therefore it is sometimes
 * a good idea to set the 'listener' to make sure they come out correctly.
 * The look verb does this.
 */
string query_room_desc() {
   string str, tmp, last_tmp = "";
   object ob, last_ob;
   object *scenery, *buildings;
   int count;

   // Start with base description.
   str = query_long();
   if( !str ) str = "This place is rather non-descript.";
   // Add scenery descriptions.
   scenery = filter(all_inventory(this_object()), (: $1->query_scenery() :));
   /*
	* For some wierd reason, the inventory_string() calls are bugging...
	* - al [aug 9, 05]
	*
   buildings = filter( scenery, (: $1->query_is_building() :) );
   if( sizeof(buildings) > 2 ) {
      scenery -= buildings;
      debug( "bld: "+as_lpc(buildings) );
      debug( "scn: "+as_lpc(scenery) );
      if( tmp[<1] != '\n' && tmp[<1] != ' ' )
         str += " ";
      str += capitalize(inventory_string(buildings)) + " are built here.";
   }
   */

   count = 1;
   last_ob = 0;
   foreach( ob : scenery ) {
      tmp = ob->query_scene_phrase();
      if( tmp ) {
         if ( tmp == last_tmp ) {
            count++;
         } else {
            if( strlen(last_tmp) > 0 && last_tmp[<1] != '\n' && last_tmp[<1] != ' ' ) str += " ";
            str += eval_exp(last_tmp, last_ob);
            if ( count > 1 )
               str += " (x" + count + ")";
            count = 1;
            last_tmp = tmp;
            last_ob = ob;
         }
      }
   }
   if( strlen(last_tmp) > 0 && last_tmp[<1] != '\n' && last_tmp[<1] != ' ' ) str += " ";
   str += eval_exp(last_tmp, last_ob);
   if ( count > 1 )
      str += " (x" + count + ")";

   return str;
}

/// \return An array of all non-scenery objects in this room.
object *query_inventory_list() {
   return filter( all_inventory(this_object()), (: !$1->query_scenery() :) );
}

/// A test function to see if the object is a room. Returns true.
int query_is_room() {
   return 1;
}

/// Fertility is based on landscape objects.
int query_fertile( int pos ) {
   object ob;
   int fertility;

   fertility = 0;
   if( !query_valid_square(CX(pos), CY(pos)) ) return 0;

   foreach( ob : filter(all_inventory(), (: $1->query_is_landscape() :)) )
      fertility = max( fertility, ob->query_fertile() );
   return fertility;
}

/** Returns whether or not teleportation is allowed from within this room.
 * A value of 0 means that the object may be ported. A value of 1 means that
 * the object is permanently prevented from teleportation, and a value of -1
 * means that teleportation is being temporarily prevented.
 */
void query_no_teleport() {
   return this_object()->query_var("no_teleport");
}

/// \param x 0 to allow teleportation, +/-1 to disallow teleportation
void set_no_teleport( int x ) {
   if (abs(x) > 1)
     x /= abs(x); // keeps flag in set [-1, 0, 1]
   this_object()->set_var("no_teleport",x);
}

object id( string s ) {
   return (s == name || s == "the ground")? this_object() : 0;
}
