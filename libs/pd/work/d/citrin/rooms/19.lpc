//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
int i, got;
void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The catwalk ends to the southwest.  The area is "
      "overrun by flies.  Several bones lay about the water under "
      "catwalk.  The boards creak from the setting of them in the "
      "mud underneath.");
    set_smell("default", "There is a horrible stench here.");
    set_exits(([
	"northeast":ROOMS"18",
	"south":ROOMS"21",
	"west":ROOMS"20",
      ]));
    set_pre_exit_functions( ({"west"}), ({"go_west"}));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

int go_west() {
    write("You climb off of the catwalk.\n");
    return 1;
}

void reset() {
    int i = 10;
    ::reset();
    if(!present("fly")) {
	while(i--) {
	    new(MON"fly")->move(this_object());
	}
    }
    i = 0;
    got = 0;
}

void init() {
    ::init();
    add_action("pull", "pull");
    add_action("get", "get");
}

int pull(string str) {
    if(!str || (str != "loose boards" && str != "board" && str != "boards")) return notify_fail("Pull what?\n");
    if(i) return notify_fail("There aren't any more loose boards.\n");	
    write("You pull on the boards causing one to come off revieling a "
      "hiding place.\n");
    i = 1;
    return 1;
}

int get(string str) {
    if (str == "bone" || str == "bones") {
	if(present("bone") || present("bones")) return 0;
	if(!i) return 0;
	if(got) return 0;

	write("You get some bones from the water.\n");
	say(this_player()->query_cap_name()+" gets some bones from the water.\n");
	got = 1;
	new(OBJ"bones")->move(this_player());
	return 1;
    }
    return 0;
}

