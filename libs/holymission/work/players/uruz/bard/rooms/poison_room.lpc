inherit "room/room";
#include "/players/trout/defs.h"
int done=0;

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "A Hidden Room";
	long_desc= "You have entered a secret bard room. There are many rooms"+
	" like this one scattered throughout the lands. It's a place where "+
	"bards can come to drop stuff, or recover from battle. There is a "+
	"small fountain in the center of the room. The water seems to sparkle"+
	", and lights up the room.\n";
	DD= ({ YY+"/workroom", "out" });
	items= ({ "water", "Sparkling blue water",
		  "room", "A room hollowed out from rock",
		  "foutain", "A small marble fountain spews fourth "+
		  "clean, blue water, ready for drinking. There's "+
		  "something written on the side of fountain"
		   "writing", "Why don't you try reading the fountain?"
		   });
	::reset(arg);
	}
init(){
	::init();
	AA("_drink", "drink");
	AA("_read", "read");
	}
_drink(string arg){
	if(!arg){
		write("Drink what?\n");
		return 1;
		}
	if(arg=="water"){
		if(done==20){
			write("You go to take a drink, but there is no more "+
			"water! Someone must have finished it all!\n");
			return 1;
			}
		write("You take a slurp of refreshing cool water from the "+
		"fountain! AHHHHHH!\n");
		call_other(TP(), "add_poison", -5);
		done= done + 1;
		return 1;
		}
	}
int _read(string arg){
	if(!arg){
		write("Read what?");
		return 1;
		}
	if(arg=="fountain"){
		write("It reads 'poison'. You wonder what that means!\n);
		return 1;
		}
	}
