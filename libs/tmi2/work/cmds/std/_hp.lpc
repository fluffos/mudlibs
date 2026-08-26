// _hp.c
// Command to show a player's hit points.
// Created by Mobydick@TMI-2, 9-23-92
// And spell points, as of 11-16-92

#include <mudlib.h>

inherit DAEMON ;

string help() ;

int cmd_hp() {
	write ("hp: "+this_player()->query("hit_points")+"/"+
		this_player()->query("max_hp")+"\n"+
	"sp: "+this_player()->query("spell_points")+"/"+
		this_player()->query("max_sp")+"\n") ;
	this_player()->block_attack(2) ;
	return 1 ;
}

string help() {
	return ("Syntax: hp\n\n"+
"The hp command shows how many hit points and spell points you have left.\n"+
"It is an alternative to the score command.\n\n"+
"See also: score\n");
}
