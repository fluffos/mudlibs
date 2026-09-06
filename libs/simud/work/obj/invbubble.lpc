#include <inven.h>
#include <object.h>

/** The Saveload system, at boot time, keeps track of objects whose
 * data files were not loaded. Their numbered data files are then
 * freed up for use by other objects. This causes a problem with player
 * inventories -- since a player's inventory is not typically present
 * at boot time, their data files get lost or overwritten.
 *
 * For this reason I came up with the inventory bubble system. The
 * gist of this is that, even though the player no longer exists on
 * the MUD, their inventory does. It will be kept in one of these
 * bubbles.
 *
 * Some inventory items will probably have heartbeats or similar.
 * It is recommended that these items be written to include a state
 * of suspended animation.
 */

string name;

object id( string str ) {
   if( str == name )
      return this_object();
   return 0;
}

string query_name() {
   return name;
}

void set_name( string str ) {
   name = str;
}

void _create_invbubble() {
   if( strstr(object_name(this_object()), "#") > 0 )
      call_out("check_contents", 0);
}

void check_contents() {
   if( !first_inventory(this_object()) )
      destruct( this_object() );
}
