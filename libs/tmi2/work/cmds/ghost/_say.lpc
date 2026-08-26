// _say.c
// The ghost's say command. It won't actually give his message, but it will
// at least indicate to live players that he's around and unhappy. Clever
// ghosts will manage to communicate using this. ("One gust for yes, two
// gusts for no. Is your corpse north of here?")
// Written by Mobydick, 11-14-92. Loosely based on the existing player _say
// command.

#include <mudlib.h>

inherit DAEMON ;

int cmd_say (string str) {
	write ("You strive to speak, but you cannot form words in your ghostly state.\n") ;
	say ("You hear the sound of distant wind.\n") ;
	return 1 ;
}
