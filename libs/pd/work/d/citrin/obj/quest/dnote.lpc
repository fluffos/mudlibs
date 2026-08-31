//  Whit
//  Citrin
#include <std.h>
#include <citrin.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("note");
    set_short("deciphered note");
    set_long("This note has some writing on it.");
    set_property("no store", 1);
    set_id(({ "note", "deciphered note", "citrin_quest_ob_4" }));
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    if(str != "note" && str != "deciphered note") return 
	notify_fail("Read what?\n");
    say(this_player()->query_cap_name()+" reads over the "
      "note.\n");
    write("I hope this information will help you well in your quest.\n\n      "
      "The Sage.\n\nIve studied the stone of circles for many years now.  "
      "Yesterday i happened to find a small key hole inside of one of the "
      "stones.  I will attempt to use the key I found near one of the "
      "stones to open it.\n\nOn the bottem of the note reads: Sic Para Bellum\n");
    return 1;
}

