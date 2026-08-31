#include <std.h>
#include <rest.h>
#include <tombar.h>

inherit ROOM;

int cracked, found;

void create() {
    ::create();
    set_name("An abandoned ship");
    set_properties(([ "light": 1, "night light": 0, "ship" : 1 ]));
    set_exits(([
		"down" : ROOMS"island/ship_1",
	]));

	set_long("This is the crows nest.  The area is relatively small, "
		"just barely big enough for one person.  A small wooden bucket "
		"is turned over providing a place to sit down.");
	set_listen("default", "Water can be heard lapping against the "
		"side of the deck.");
	set_smell("default", "The smell of rotting wood lingers.");
	set_items(([ 
		"fish" : "The fish are floating dead in the water.",
		({ "sails", "white sails" }) : "The white sails flap in the "
			"wind.  The sails are riddled with tears and rips.",
		({ "crate", "crates" }) : "Several crates are sprawled out "
			"across the deck.  One of the crates has a strange marking "
			"on it.",
	]));

}

void reset() {
	::reset();
	cracked = 0;
	found = 0;
}

void init() {
	::init();
	add_action("sit_bucket", "sit");
	add_action("search_bucket", "search");
}

int sit_bucket(string str) {
	if(this_player()->query_rest_type()) return 0;

	if(cracked) {
		write("The bucket is broken!");
		return 1;
	}

	cracked = 1;
	write("You sit down and the bucket breaks under your weight.");
	this_player()->set_rest_type(SIT);
	return 1;
}

int search_bucket(string str) {
	if(!str || str != "bucket") return 0;

	if(!cracked || found) return notify_fail("You look around but find nothing.");
	write("You search under the bucket and find a telescope.");
	new(OBJ+"telescope");
	found = 1;

	return 1;
}
