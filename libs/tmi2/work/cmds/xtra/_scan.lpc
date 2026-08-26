// _scan.c
// Equivalent to typing "look direction" for each exit in the room.
// Mobydick, 3-11-94
// Part of the TMI-2 mudlib. Use this improperly and ten plagues will
// descend upon your household to the third generation.

#include <mudlib.h>

inherit DAEMON ;

int cmd_scan() {

	mapping exits ;
	string *directions ;
	int i ;

	exits = environment(this_player())->query("exits") ;
        if (!exits || !mapp(exits)) {
            write("There are no exits here.\n");
            return 1;
        }
	directions = keys(exits) ;
	this_player()->set_temp("force_to_look",1) ; 
	for (i=0;i<sizeof(directions);i++) {
	    this_player()->force_me("look "+directions[i]) ;
	}
	this_player()->set_temp("force_to_look",0) ;
	return 1 ;
}
