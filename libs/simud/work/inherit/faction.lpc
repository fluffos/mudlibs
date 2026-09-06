#include <const.h>

/** This object contains getters, setters, and operations for
 * working out information about factions. It's intended to
 * be used primarily by objects which can participate in conflict
 * and need an automated way to differentiate friend from foe.
 */

void set_faction( string x ) { SBODY( "faction", x ); }

string query_faction() { QBODY( "faction", this_object()->query_name() ); }
