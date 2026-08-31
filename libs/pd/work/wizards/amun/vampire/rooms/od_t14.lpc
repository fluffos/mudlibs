#include <std.h>
#include <vampq.h>
inherit VR+"sun_room";
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "outdoors" : 1, "night light" : 0 ]));
    set("short", "Outdoors");
    set_long("%^BOLD%^%^YELLOW%^This area is different than the others. The vegetation seems to be abundant, especially the %^GREEN%^bright green bushes %^YELLOW%^just off the path. A soft wind flows through the area allowing the screeching sounds to filter through.%^RESET%^");
    set_items((["vegetation" : "%^BOLD%^%^GREEN%^The area is full of vegetation, but there is something interesting about the bushes.%^RESET%^", "bushes" : "%^BOLD%^%^GREEN%^These bushes look as if they've somehow been parted recently. Maybe you should examine them a bit more.%^RESET%^" ]));
    set_exits( ([ "northwest" : VR"od_t16" ]) );
}
void init() {
    ::init();
    add_action("search", "search");
}

int search(string str) {
    if (str == "bushes") {
	write("%^BOLD%^%^GREEN%^You feel a tug at your stomach and fall forward into the bushes.%^RESET%^");
	this_player()->move_player(VR"g_6");
	this_player()->add_hp(-200);
	this_player()->set_paralyzed(5);
	return 1;
    }
    write("Hmmm...There is still something interesting about these bushes.");
    return 1;
}
