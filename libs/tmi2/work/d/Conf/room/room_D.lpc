// my_room.c
// Example conference room
// Mobydick@TMI-2, 2-1-93.

inherit "/d/Conf/conf_room" ;

void create() {
	::create() ;
	set ("light", 1) ;
	set ("short", "The conference room.\n") ;
	set ("long",
"This is meeting room D, in which structured discussion may be held.\n"+
"There is a long table with a large number of chairs around which the\n"+
"discussants may sit. At the head of the table is a large chair which is\n"+
"labeled \"Moderator\". A large sign on the wall shows the current status\n"+
"of the meeting room.\n"+
"You can reach the conference center by typing 'out'.\n"
	) ;
	set ("exits", ([
		"out" : "/d/Conf/room/centre"
	]) ) ;
	set_echo_room ("/d/Conf/room/spec_roomD") ;
	logfile = "room.D.log" ;
	votefile = "votes.D.log" ;
	call_other ("/d/Conf/boards/conf_D", "frog") ;
        call_other ("/d/Conf/obj/vendor_D", "frog") ;
}
