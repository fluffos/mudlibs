//  Whit

#include <std.h>
#include <event.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("journal");
    set_short("journal of a young adventurer");
    set_long("The journal has 3 entries in it.  Type <read [entry #]> to read it.");
    set_id(({ "journal" }));
}

void init() {
    ::init();
    add_action("read", "read");
}

int read(string str) {
    if(str != "1" && str != "2" && str != "3") {
	write("There are only three entries in the journal.\n");
	return 1;
    }

    say(this_player()->query_cap_name()+" reads over the journal.\n");
    if(str == "1") {
	write("Journal Entry 1 reads:\n"
	  "I am so happy to finally be a part of such a wonderful world.  "
	  "I have discovered many new things.  Most of the other people "
	  "seem nice and help me along very well.\n");
	return 1;
    }
    if(str == "2") {
	write("Journal Entry 1 reads: \n"
	  "I was walking around today when something came out of the bushes and "
	  "attacked me.  I can safely say that i killed my first monster today.  "
	  "Along with that i came across a large city.  Near the center of the "
	  "city a bard named Tryst sung me a song about the city.\n");
	return 1;
    }
    if(str == "3") {
	write("Journal Entry 1 reads: \n"
	  "I wondered the streets of the city somemore today.  There are many "
	  "guards here.  They seem like they are protecting something very "
	  "valuble.  I found a temple to the north.  Many strange things "
	  "live inside of it.  Apon wondering inside a stumbled onto a dusty "
	  "book.  I took it and brought it back to my camp on the outskirts "
	  "of Lodos.");
	return 1;
    }

}

