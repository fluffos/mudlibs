// _protect.c
// The protection command. One player may protect another. If A protects B,
// then all attacks directed against player B hit player A instead.
// Protection loops are not allowed; that is, if A protects B and B
// protects C, then attacks against A hit B regardless of C's best
// intentions.
// This makes it possible for fighters to protect spellcasters while
// spells are cast, for high-skill players to protect low-skill ones,
// whatever you like.
// Mobydick, 6-13-93

#include <mudlib.h>

inherit DAEMON ;

int help() ;

int cmd_protect (string str) {

	object damsel ;
	string *foo ;

	if (!str) return help() ;
	damsel = present(str,environment(this_player())) ;
	if (!damsel || !userp(damsel)) {
		notify_fail ("There's no one by that name to protect.\n") ;
		return 0 ;
	}
	write ("You begin protecting "+capitalize(str)+".\n") ;
	tell_object (damsel, this_player()->query("cap_name")+
		"begins protecting you.\n") ;
	damsel->add("protectors", ({ this_player()->query("name") }) ) ;
	this_player()->add("protectees", ({ str }) ) ;
	return 1 ;
}

int help() {
	write ("Usage: protect <player>\n\n"+
"The protect command lets you protect a given player against attacks by\n"+
"monsters or other players. If you are protecting another player, then\n"+
"when you are in the same room as that player, all weapon attacks against\n"+
"that player will hit you instead. Spell attacks will not be stopped.\n"+
"\nSee also: unprotect.\n") ;
	return 1 ;
}
