#include <std.h>
#include <tombar.h>

inherit ROOM;
int searched;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("night light", 2);
    set_property("beach",1);
    set_short("Shores of Tombar");
	set_long("The shores are covered in a black, oily sand.  Remnants of old trees "
		"remain scattered about shores.  Branches have been strewn over the area "
		"making the sand crunchy when stepping.  The waves from the ocean wash "
		"over the beach, carrying the black substance back into the ocean with it.");
	set_items( ([
		"sand" : "The sand is black.  How strange."]) );
    set_exits( ([
		"west" : ROOMS"island/1"]) );
}

void init() {
   ::init();
   add_action("search_sand", "search");
}

int search_sand(string s) {
   if(searched) return 0;
   write("Digging in the sand, you find a small black orb.");
   say(this_player()->query_cap_name()+" digs through the sand and finds a black orb.\n");
   new(OBJ"black_orb")->move(this_player());
   searched=1;
   return 1;
}

void reset() {
   ::reset();
   searched=0;
}
