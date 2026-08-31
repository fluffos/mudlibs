//  Whit
//  Citrin
#include <std.h>
#include <citrin.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("note");
    set_short("a plain note");
    set_long("The note has some old writing on it.  It is most "
      "likely you cannot read the text on it.");
   set_property("no store", 1);
    set_id(({ "note", "plain note", "citrin_quest_ob" }));
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    if(str != "note" && str != "plain note") return 
	notify_fail("Read what?\n");
    say(this_player()->query_cap_name()+" attemps to read the "
      "note but fails.\n");
    write("The note is in some kind of forgotten language.  Only "
      "very few people know what it says.  Perhaps you can find "
      "someone to read it.\n");
    return 1;
}

