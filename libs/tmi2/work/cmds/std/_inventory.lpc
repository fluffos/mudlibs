/*
// This file is part of the TMI Distribution Mudlib.
// Please include this header if you use this code.
// Slick Ace, 01/02/91
// Help added by Brian (1/28/92)
// Rewritten by Buddha to show equipped items properly (2/3/92)
// Changed by Mobydick@TMI-2 (9/16/92) to capitalize short descriptions
// and to handle the new equipping system.
// Replaced the hardcoded weight limit with included #defines. Moby, 4-26-93
*/

#include <move.h>
#include <user2.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_inventory() {

   object *items ;
   int i, x, wt, bk, count;
   string result, tmp;

   this_player()->block_attack(4) ;
   count = 0;
   items = all_inventory(this_player());
   for (i = 0; i < sizeof(items); i++)
      if (items[i]->query("short"))
         count++;
// A player has a maximum capacity of 5000 mass units and a maximum volume
// of 500 bulk units. A monster's capacity and volume maxima are set in
// the properties "max_cap" and "max_vol". It would be possible to set
// player properties instead, but hard-coding is more robust.
	if (this_player()->query("npc")) {
		wt = (int)this_player()->query("max_cap") -
			(int)this_player()->query("capacity") -
			(int)this_player()->coins_carried() ;
		bk = (int)this_player()->query("max_vol") -
			(int)this_player()->query("volume") ;
	} else {
		wt = MAX_CAPACITY - (int)this_player()->query("capacity") -
			(int)this_player()->coins_carried() ;
		bk = MAX_VOLUME-(int)this_player()->query("volume") ;
	}
   result ="You are carrying " + count + " objects. (Total bulk: " + 
	bk + " Total weight "+wt+")\n" ;
   for (x=0; x < sizeof(items); x++) {
      if(tmp=(string)items[x]->query("short")) {
	if (items[x]->query("wielded")) tmp = tmp + " (wielded)" ;
	if (items[x]->query("equipped")) tmp = tmp + " (equipped)" ;
	if (items[x]->query("invisible")) tmp = tmp + " (invisible)" ;
	 result += capitalize(tmp)+".\n" ;
	}
   }
   write(result);
   return 1;
}

string help() {
   return("Syntax: inventory\n\n"+
      "This command gives you a list of the items\n"+
      "contained in your inventory.\n");
}
/* EOF */
