// _unwield.c
// Command to unwield weaponry.
// Mobydick@TMI-2, 9/17/92

#include <mudlib.h>

inherit DAEMON ;

int cmd_unequip(string str) {

	object obj ;
	string name ;
	int Class ;
 
  	notify_fail("Unequip what?\n");
	if(!str || str == "")  return 0;

	obj = present (str,this_player()) ;
	if (!obj) {
		notify_fail ("You don't possess a "+str+".\n") ;
		return 0 ;
	}
	Class = obj->query("armor") ;
	if (!Class) {
		notify_fail ("That isn't armor.\n") ;
		return 0 ;
	}
	if (obj->query("equipped")) {
// Unequip it in this case.
// The unequipping code is in the armor object because several commands
// (drop, dest, give) can force the player to unwield the weapon and they
// all need access to it. The player can only wield the weapon using the
// wield command, so that code is a command.
		obj->unequip() ;
		this_player()->block_attack(6) ;
		return 1 ;
	}
	notify_fail ("It is not equipped.\n") ;
	this_player()->block_attack(2) ;
	return 0 ;
}

int help() {
	write ("Usage: unequip <armor>\n\n"+
"This command lets you remove armor that you have equipped.\n"+
"\nSee also: equip\n") ;
	return 1 ;
}
