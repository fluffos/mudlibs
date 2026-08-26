// dispenser.c
// Creates piles of coins and drops them at the player's feet.
// You probably don't want these where players can get at them.
// However, it's a good object for testing changes to the money system.
// Created by Mobydick@TMI-2, 8-24-92

#include <money.h>
#include <mudlib.h>

inherit OBJECT ;

void create() {
	seteuid(getuid()) ;
	set ("short", "a money dispenser") ;
	set ("long",
	"It is shaped rather like a tree, and coins of various types are\n"+
	"hanging off of the branches in clusters. Type 'help dispenser'.\n") ;
	set ("mass", 100) ;
	set ("bulk", 30) ;
	set ("id", ({ "dispenser" }) ) ;
}

void init() {
	add_action ("vend", "vend") ;
	add_action ("help", "help") ;
}

// Vend clones a pile of coins, sets the type of coins and the number, and
// places it in the player's environment. The player will still have to pick
// it up to get it into his purse.

int vend(string arg) {

	string type ;
	int number ;
	object obj ;

	if (sscanf(arg,"%d %s",number,type) != 2) {
		notify_fail ("Usage: vend <number of coins> <type of coin>\n") ;
		return 0 ;
	}
	if (number<1) {
		write ("Hardly. Please try a positive number of coins.\n") ;
		return 1 ;
	}
	obj = clone_object(COINS) ;
	obj->set_type(type) ;
	obj->set_number(number) ;
	obj->move(environment(this_player())) ;
	write ("You push the buttons and "+number+" "+type+" coins pop out.\n") ;
	say (this_player()->query("cap_name")+" vends "+number+" "+type+" coins.\n") ;
	return 1 ;
}

int help (string str) {

	if (!str || str!="dispenser") {
		return 0 ;
	}
	write (
"This is a money dispenser. Typing 'vend <number> <type>' will cause coins\n"+
"of the given number and type to appear at your feet.\n") ;
	return 1 ;
}
