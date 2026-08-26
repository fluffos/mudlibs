/*    /lib/inventory.c
 *    from the Foundation II LPC Library
 *    gives a person information about their inventory
 *    created by Descartes of Borg 950412
 */

#include <lib.h>

inherit LIB_DAEMON;

void eventInventory();

mixed cmd(string args) {
    mapping borg;
    string *shorts;
    string ret;
    int i;

    shorts = map(filter(all_inventory(this_player()), 
			(: !((int)$1->GetInvis(this_player())) :)),
		 (: (string)$1->GetShort() :));
    borg = ([]);
    if( !(i = sizeof(shorts)) ) {
	message("system", "You are carrying nothing.", this_player());
	return 1;
    }
    if( i == 1 ) ret = "You are carrying just this one item:\n";
    else ret = "You are carrying the following items:\n";
    while(i--) if( shorts[i] ) borg[shorts[i]]++;
    i = sizeof(shorts = keys(borg));
    while(i--) ret += capitalize(consolidate(borg[shorts[i]], shorts[i]))+"\n";
    message("system", ret, this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <inventory>\n\n"
	    "Lists all items you are carrying currently.  This command "
	    "will take up one round of combat if you happen to be in "
	    "combat.", this_player());
}
