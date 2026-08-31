#include <std.h>
#include <vampq.h>
inherit ROOM;
void create() {
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "outdoors" : 1, "night light" : 0 ]));
    set("short", "Outdoors");
    set_long("%^BOLD%^%^BLACK%^Description..blah blah..A large gate can be seen to the north.%^RESET%^");
    set_items((["vegetation" : "%^BOLD%^%^BLACK%^There is no vegetation in the area.%^RESET%^", "sun" : "%^BOLD%^%^YELLOW%^The sun is beating down on you as if trying to take your life away.%^RESET%^" ]));
    add_pre_exit_function("gate", "go_gate");
    set_exits( ([ "southwest" : VR"g_3", "south" : VR"g_4", "southeast" : VR"g_5" ]) );
}
void reset() {
    if(!present("large gate"))
	new(VO"large_gate")->move(this_object());
}
void init() {
    ::init();
    add_action("insert_fang", "insert");
}
int go_gate() {
    if (!present("large gate")) {
	return notify_fail("The gate blocks your way!\n");
    }
    else {
	return 1; }
}
int insert_fang(string str) {
    if (!present("fang", this_player())) {
	return notify_fail("What did you do with the fang?\n");
    }
    if (!str || str != "fang") {
	return notify_fail("Insert what?\n");
    }
    write("%^BOLD%^%^RED%^You insert the fang into the gate. \n %^BOLD%^%^RED%^You are pulled into a trance as you walk through the gate.");

    this_player()->move_player(VR"transroom3");
    find_object(VR"transroom3")->start_fmv("vision");
    return 1;
}
