/*
// This file is part of the TMI Distribution Mudlib.
// Please include this header if you use this code.
// Slick Ace, 01/02/91
// Help added by Brian (1/28/92)
// Rewritten by Buddha to show equipped items properly (2/3/92)
// Changed by Mobydick@TMI-2 (9/16/92) to capitalize short descriptions
// and to handle the new equipping system.
// Replaced the hardcoded weight limit with included #defines. Moby, 4-26-93
// (28 May 97) Cyanide accounted for not having any items or just money.
//      Accounted for which hand a weapon is wielded in.
// ( 1 Jul 97) Cyanide improved upon the previous inprovement.  ;)
*/

#include <move.h>
#include <user2.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_inventory() {

    object *items ;
    int i, x, wt, bk, count;
    string result, tmp;

    count = 0;
    items = all_inventory(this_player());
    for (i = 0; i < sizeof(items); i++)
	if (items[i]->query("short"))
	    count++;
	// A player has a maximum capacity of 5000 mass units and a maximum volume
	// of 500 bulk units. A monster's capacity and volume maxima are set in
	// the properties "max_cap" and "max_vol". It would be possible to set
	// player properties instead, but hard-coding is more robust.
    wt = (int)this_player()->query("capacity");
    wt = (int)this_player()->query("max_cap") - wt;

    if (count<1) result = "You are carrying:";
    else {
	if (count == 1) result = "You are carrying 1 object: ";
	else  
	    result ="You are carrying " + count + " objects:";
	//this_player()->fix_volcap();
    }

    result += " (Total encumberance: " + wt + " lbs.";

    wt*=100;
    wt = wt/((int)TP->query("max_cap"));

    result += " ("+wt+"%))\n";

    if (TP->total_wealth()) {
	if ((int)TP->total_wealth() == 1) result += "   1 credit.\n";
	else result += "   "+TP->total_wealth() + " credits.\n";
    }

    for (x=0; x < sizeof(items); x++) {
	if(items[x]->query("short")) {
	    tmp="   "+capitalize((string)items[x]->query("short"));
	    if (items[x]->query("wielded")==1) tmp = tmp + 
		" (wielded in right hand)" ;
	    if (items[x]->query("wielded")==2) tmp = tmp +
		" (wielded in left hand)" ;
	    if (items[x]->query("wielded")==3) tmp = tmp +
		" (wielded in both hands)" ;
	    if (items[x]->query("equipped")) tmp = tmp + " (equipped)" ;
	    if (items[x]->query("invisible")) tmp = tmp + " (invisible)" ;
	    result += capitalize(tmp)+".\n" ;
	}
    }
    if (count<1 && !TP->total_wealth()) result += "Nothing.\n";
    write(result);
    return 1;
}

string help() {
    return("Syntax: inventory\n\n"+
      "This command gives you a list of the items\n"+
      "contained in your inventory.\n");
}
/* EOF */
