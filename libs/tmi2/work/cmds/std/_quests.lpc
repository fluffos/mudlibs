// _quests.c
// Tells the player how many quests he has left to solve.
// Mobydick@TMI-2, 11-12-92. My birthday.

// Don't forget to update NUM_QUESTS when you add a new quest!
// Also, don't forget to update the Book of Quests in the hall,
// and the promotion requirements in the wizard promotion room
// (which is /d/Fooland/hall2 in the default mudlib).

#define NUM_QUESTS 1
#include <mudlib.h>

inherit DAEMON ;

int cmd_quests() {

	mapping solved ;
	int i,j ;
	string *names ;
	string word ;

	solved = this_player()->query("quest") ;
	if (!solved || solved == ([])) {
		write ("You have not yet solved any quests.\n") ;
		j = NUM_QUESTS ;
	} else {
		j = 0 ;
		names = keys(solved) ;
		for (i=0;i<sizeof(names);i++) {
			if (solved[names[i]]==1) {
				write ("You have solved the "+names[i]+" quest.\n") ;
				j = j+1 ;
			}
		}
		j = NUM_QUESTS - j ;
	}
	if (j==0) {
		write ("You have solved all of the quests on this MUD.\n") ;
	} else {
		if (j==1) word = "quest" ; else word = "quests" ;
		write ("You have "+j+" "+word+" left to solve.\n") ;
	}
	return 1 ;
}

int help() {
	write ("Usage: quests\n"+
"The quests command will tell you which quests you have solved, and how\n"+
"many quests you have left to solve.\n") ;
	return 1 ;
}
