// _spells.c
// Lists a player's known spells.
// Mobydick@TMI-2, 1-31-93. Mobydick doesn't care who wins the Super Bowl.

#include <mudlib.h>

inherit DAEMON ;

int cmd_spells() {

	int i ;
	string *known ;

	known = this_player()->query("spells") ;
	if (!known || sizeof(known)==0) {
		write ("You haven't learned any spells yet.\n") ;
		return 1 ;
	}
	write ("You know the following spells:\n") ;
	for (i=0;i<sizeof(known);i++) {
		write ("    "+capitalize(known[i])+"\n") ;
	}
	return 1 ;
}

int help() {
	write ("Usage: spells\n\n"+
"The spells command will list the names of all the spells you know.\n"+
"See also: cast, magic.\n") ;
	return 1 ;
}
