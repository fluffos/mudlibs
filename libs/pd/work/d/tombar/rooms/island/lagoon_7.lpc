#include <std.h>
#include <tombar.h>

inherit ROOM;
int rope_broke;

void create() {
    ::create();
    set_name("Tombar Lagoon");
    set_properties(([ "light": 1, "night light": 0 ]));
    set_exits(([
		"southwest" : ROOMS"island/lagoon_6",
	]));
	set_long("The winding path comes to a halt at the side of a ship.  "
		"The hull of the ship has slowly rotted away leaving gapping "
		"holes preventing it from being seaworthy.  The ships black sails "
		"slightly blow in the wind.  Large holes are seen in the sails.  "
		"A rope ladder is draped down over the hull leading up to the deck "
		"of the ship.  Two large ropes are tied from the hull to two stronger "
		"looking tree stumps.");
	set_listen("default", "Flying bugs create a small buzzing sound.");
	set_smell("default", "The smell of death and decay lingers.");
	set_items(([ 
		"fish" : "The fish are floating dead in the water.",
		"ship" : "The ship looks as if its been floating in the lagoon "
			"for a long time.  It's hull is badly damaged and the black "
			"sails have been torn making it impossible for the ship to "
			"sail.",
		({ "holes", "hole" }) : "Holes have formed in the side of the "
			"hull.  The edges are black from the rotting.",
		({ "sails" }) : "The sails have been torn from the wind.",
		({ "plank", "wooden plank" }) : "The wooden plank stretchs up "
			"to the side of the ship.  The wood is black and covered in "
			"rot.  Below the ocean can be seen beating up against the ship.",
	]));

}

void init() {
	::init();
	add_action("climb_rope", "climb");
}

int climb_rope(string str) {
	if(!str || str != "rope") return notify_fail("Climb what?\n");
	
	if(rope_broke) return notify_fail("The rope is broke and cannot be climbed.\n");

	if(!random(10)) {
		rope_broke = 1;
		say(this_player()->query_cap_name() + " tries to climb the rope but it breaks and " + nominative(this_player()) + " falls.");
		write("The rope breaks in your hand and you fall.");
		return 1;
	}

	this_player()->move_player(ROOMS"island/ship_1", "up the rope");
	return 1;
}

void reset() {
	::reset();
	rope_broke = 0;
}

