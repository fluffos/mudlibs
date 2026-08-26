//  Original write: Tzar@Earth
//
// Leto thinks that's highly unlikely. Even the tmi-2 0.9 lib
// probably didn't come without a say command :)
// Leto removed some silly arguments to say() and idented the code
// so it would be readable, and optimized Tzar's code quite a bit :)
// say() doesn't work correctly for amcp yet, Leto
// Leto removed iwraps, 160296
// Leto changed all message classes to "say", 030396
// MASSIVELY overhauled by Cyanide 28 August 1997 to support for invis 
//   shit - streamlined in the process..
// (04-23-98) Chronos changes the wrap()'s to iwrap()'s so things look 
//            prettier.  Also removed the extra \n from You say: line. :D

#include <mudlib.h>

inherit DAEMON;

int cmd_say(string str) {
    int last, x;
    object *people;
    string nam, verb_a = "say", verb_b = "says" ;

    people = all_inventory(environment(this_player()));
    //this_player()->block_attack(2) ;
    if ((!str) || (str == " ")) {
	message("error","[say] Usage: say <message>\n", this_player() );
	return 1;
    }
    last = str[<1];

    if (last == '?') {
	verb_a = "ask";
	verb_b = "asks";
    }
    if (last == '!') {
	verb_a = "exclaim";
	verb_b = "exclaims";
    }

    for (x=0;x<sizeof(people);x++) {
	if (!living(people[x])) continue;
	if (people[x]==this_player()) {
	    message("say", iwrap("You "+verb_a+": "+str), TP) ;
	} else {
	    if (visible(TP, people[x])) { 
		message("say", iwrap(TPN+" "+verb_b+": "+str), people[x]) ;
	    } else {
		tell_object(people[x], iwrap("Somebody "+verb_b+": "+str) );
	    }
	}
    }
    return 2;
}

string help() {

    return @HelpText

Usage:  say <message>

The say command sends your <message> to everyone in the current room.

HelpText;
}


