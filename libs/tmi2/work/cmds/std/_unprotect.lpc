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

int cmd_unprotect (string str) {

	object damsel ;
	string *foo ;

	if (!str) return help() ;
	damsel = present(str,environment(this_player())) ;
	if (!damsel || !userp(damsel)) {
		notify_fail ("There's no one by that name to protect.\n") ;
		return 0 ;
	}
	foo = damsel->query("protectors") ;
	if (member_array((string)this_player()->query("name"),foo)==-1) {
		notify_fail ("You are not protecting "+capitalize(str)+".\n");
		return 0 ; 
	}
	write ("You stop protecting "+capitalize(str)+".\n") ;
	tell_object (damsel, this_player()->query("cap_name")+
		"stops protecting you.\n") ;
	foo = damsel->query("protectors") ;
	foo -= ({ this_player()->query("name") }) ;
	damsel->set("protectors",foo) ;
	foo = this_player()->query("protectees") ;
	foo -= ({ str }) ;
	this_player()->set("protectees", foo) ;
	return 1 ;
}

int help() {
	write ("Usage: unprotect <player>\n\n"+
"If you are protecting <player> against attacks, then the unprotect\n"+
"command will allow you to stop protecting them.\n"+
"\nSee also: protect.\n") ;
	return 1 ;
}
