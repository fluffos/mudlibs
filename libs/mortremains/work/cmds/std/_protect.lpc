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
//
// 5 Nov 97  Cyanide repaired the ongoing confusion in protectors and
//           strings vs. objects.

#include <mudlib.h>

inherit DAEMON ;

string help();

int cmd_protect (string str) {
    object damsel, *prot ;
    string *foo ;

    if (!str) {
	write(help());
	return 1;
    }

    damsel = present(str,environment(this_player())) ;
    if (!damsel) {
	notify_fail ("There's no one by that name to protect.\n") ;
	return 0 ;
    }

    prot = damsel->query("protectors");
    if (!prot) prot = ({});

    if (member_array(TP, prot)!=-1) {
	write("You are already protecting "+damsel->query("cap_name")+
	  ".\n");
	return 1;
    }

    write ("You begin protecting "+capitalize(str)+".\n") ;
    tell_object (damsel, this_player()->query("cap_name")+
      " begins protecting you.\n") ; 
    damsel->add("protectors", ({ this_player() }) ) ;
    this_player()->add("protectees", ({ damsel }) ) ;
    return 1 ;
}

string help() {
    return ("Usage: protect <player>\n\n"+
      "The protect command lets you protect a given player against attacks by\n"+
      "monsters or other players. If you are protecting another player, then\n"+
      "when you are in the same room as that player, all weapon attacks against\n"+
      "that player will hit you instead. Spell attacks will not be stopped.\n"+
      "\nSee also: unprotect.\n") ;
}
