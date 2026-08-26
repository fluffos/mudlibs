// The tower on the grid. Entered from grid room 10,13.
// Might not be a bad idea to eventally disconnect it, otherwise players
// will get in here.
// Mobydick@TMI-2, 9-3-92

#include <mudlib.h>

inherit ROOM ;

void create () {

	object ob ;

	::create();
	seteuid(getuid()) ;
	set ("light", 1) ;
	set ("short", "Wizard Headquarters") ;
	set ("long",
"You are in the wizard's lounge on this MUD. Wizards hang out here and\n"+
"generally have a good time. To the north is the archive reading board,\n"+
"which lets wizards read the archived posts from the bulletin boards. To\n"+
"the south is the wizard conference room where wizard meetings may be\n"+
"held. East will take you to the adventurer's hall in Fooland, and out\n"+
"will put you out on the wilderness grid. A winding stone staircase\n"+
"leads up the the next floor of the tower.\n") ;
	set ("exits", ([
		"east" : "/d/Fooland/hall",
		"up" : "/d/Fooland/tower2",
		"west" : "/d/Fooland/vote_room",
		"south" : "/d/Fooland/conf_room",
		"north" : "/d/Fooland/archiverm",
		"out" : "/d/grid/rooms/10,13.grid",
	]) ) ;
	set ("exit_msg", ([
	"east" : "$N takes a little trip to Footown.",
	]) ) ;
}
