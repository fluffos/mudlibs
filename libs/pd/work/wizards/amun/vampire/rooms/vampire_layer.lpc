#include <std.h>
#include <vampq.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1 ]));
    set("short", "Layer");
    set_long("%^BOLD%^%^BLACK%^The bottom area of the lair is black as night. The only thing that can be seen is a black stone altar that is placed in the middle of the room. The altar is %^RED%^glowing %^BLACK%^softly as if inviting anyone around to move closer for a better look. There is no sound in the room at all, it is as if all life does not exist.%^RESET%^");
    set_items((["altar" : "%^BOLD%^%^BLACK%^The st%^RED%^o%^BLACK%^ne al%^RED%^t%^BLACK%^ar sits in the middle of the room. It is beckoning anyone around to come forward. It's so pretty to look at, but how does it feel to the touch?%^RESET%^" ]));
}
void init() {
    ::init();
    add_action("touch", "touch");
}
int touch(string str) {
    if (str == "altar") {
	write("%^BOLD%^%^RED%^You touch the altar and your stomach begins to churn.%^RESET%^"); 
	this_player()->move_player(VR"transroom4");
	find_object(VR"transroom4")->start_fmv("vampire");
	this_player()->add_hp(-200);
	return 1;
    }
    write("The altar is calling you to touch it.");
    return 1;
}
