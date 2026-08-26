// _unwield.c
// Command to unwield weaponry.
// Mobydick@TMI-2, 9/17/92

#include <mudlib.h>  

inherit DAEMON ;

int cmd_unwield(string str) {

	object obj, firstwep, secondwep ;
	string name ;
	int Class ;

	if (!str) {
		notify_fail ("What would you like to unwield?\n") ;
		return 1 ;
	}
	obj = present (str,this_player()) ;
	if (!obj) {
		notify_fail ("You don't possess a "+str+".\n") ;
		return 0 ;
	}
	Class = obj->query("weapon") ;
	if (!Class) {
		notify_fail ("That isn't a weapon.\n") ;
		return 0 ;
	}
	this_player()->block_attack(2) ;
	firstwep = this_player()->query("weapon1") ;
	secondwep = this_player()->query("weapon2") ;
	if (obj==firstwep || obj==secondwep) {
// Unwield it in this case.
// The unwielding code is in the weapon object because several commands
// (drop, dest, give) can force the player to unwield the weapon and they
// all need access to it. The player can only wield the weapon using the
// wield command, so that code is a command.
		obj->unwield() ;
		return 1 ;
	}
	notify_fail ("It is not wielded.\n") ;
	return 0 ;
}

int help() {
	write ("Usage: unwield <weapon>\n\n"+
"This command lets you stop using a weapon you have wielded.\n"+
"\nSee also: wield\n") ;
	return 1 ;
}
