#include <std.h>
#include <tombar.h>

inherit ROOM;
int open;

void create() {
    ::create();
    set_name("Island of Tombar");
    set_properties(([ "light": 1, "night light": 1 ]));
    set_exits(([
		"south" : ROOMS"island/1",
		"north" : ROOMS"island/4",
	]));
	set_long("Remnants of old trees remain from the life that no longer grows "
		"on the island.  The trees look shattered as if by an inside force "
		"had caused them to explode from the inside out spreading "
		"the wood splinters onto the beach.  Small bugs litter the ground "
		"crawling over the splinters of wood.");
	set_items(([
		({ "tree", "trees" }) : "The trees seem to have been ripped apart.  "
			"The remnant trunks have been reduced to splinters.",
		({ "spinters", "wood" }): "The wood seems to be turning black from rot.",
		({ "bug", "bugs"  }) : "The bugs scurry over the ground eatting on the rotting wood.",
	]));
}

