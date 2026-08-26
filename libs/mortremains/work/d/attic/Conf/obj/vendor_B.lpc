// A note dispensor.
// Used by people who wish to submit resolutions or amendments.
// Created by Mobydick@TMI-2, 10-12-92
// Set up to dispense notes by Moby, 1-19-92

#define FILE_NAME "/obj/note"

inherit "/std/object/ob" ;

int set_location (string str) ;

void create () {
	seteuid(getuid()) ;
	set ("short", "A note dispenser") ;
	set ("long",
"This machine will give you a note if you 'vend' one. You can write the\n"+
"note and then post it to the board. Or you can post to the board directly.\n") ;
	set ("id", ({ "vendor", "dispenser", "note machine" }) ) ;
	set_location ("/d/Conf/room/room_B") ;
}

void init() {
	add_action ("vend", "vend") ;
}

int vend() {

	object ob ;

	ob = clone_object(FILE_NAME) ;
	ob->move(this_player()) ;
	write ("A note appears in your hands.\n") ;
	return 1 ;
}

void set_location(object place) {
	::move(place) ;
}

int move(mixed dest) {
	return 1 ;
}
