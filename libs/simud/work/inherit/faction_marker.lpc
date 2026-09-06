#include <const.h>

/** This is for items that mark you as belonging to a faction.
 * Can be medals, armour, whatever.
 */

string faction;

/** Marks that this item identifies a faction.
 */
int query_is_faction_marker() { return 1; }

/** Lets you set the faction associated with this item.
 */
void set_faction( string x ) { faction = x; }

/** Lets you query the faction associated with this item.
 */
string query_faction() { return faction; }

int on_wear() {
   object ob;

   foreach( ob : all_inventory(this_player()) )
      if( ob->query_is_faction_marker() )
         ob->remove_armour();
   this_player()->set_faction( query_faction() );
   return 0; // Perform default wearing action as well.
}

int on_remove() {
   this_player()->remove_var( "faction" );
   return 0; // Remove it normally.
}
