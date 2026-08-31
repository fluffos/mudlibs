//  Whit
//  Citrin
#include <std.h>
#include <citrin.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("book");
    set_short("a odd looking book");
    set_long("This book looks old.  You cannot read the text inside.");
    set_id(({ "odd book", "odd looking book", "book", "citrin_quest_ob_2" }));
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    if(str != "book") return 
	notify_fail("Read what?\n");
    say(this_player()->query_cap_name()+" attemps to read the "
      "book but fails.\n");
    write("You do not have enough knowlege to read this ancient language.\n");
    return 1;
}

