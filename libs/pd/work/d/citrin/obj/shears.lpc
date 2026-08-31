//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit OBJECT;

void init() {
    ::init();
    add_action("cut", "cut");
}

void create() {
    ::create();
    set_name("shears");
    set_short("cutting shears");
    set_long("This is a nice pair of long handled cutting shears.  It "
      "looks as if it could cut anything down.");
}

int cut(string str) {
    if(!str) {
	write("Cut what?\n");
	return 1;
    }
    if(!environment(this_player())->query_property("cuttable")) {
	write("Cut what?\n");
	return 1;
    }
    if(environment()->is_cut()) {
	write("There is nothing left to cut.\n");
	return 1;
    }
    write("You hack away at the grass with your cutting shears.\n");
    say(this_player()->query_cap_name()+" cuts away at the long grass.");
    environment(this_player())->set_cut(1);
    return 1;
}


