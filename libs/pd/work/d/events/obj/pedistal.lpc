#include <std.h>

inherit OBJECT;

int lock;

void create() {
    ::create();
    set_name("pedistal of demons");
    set_long("The pedistal has been carved from the finest of "
      "stone.  A snake lock shaped like a triangle protects the "
      "book ontop of it "
      "from being touched.  Vines climb up the sides of the "
      "pedistal");
    set_id(({ "pedistal", "pedistal of demons" }));
    set_short("a stone pedistal");
    lock = 1;
}

void init() {
    ::init();
    add_action("take", "take");
    add_action("unlock", "unlock");
}

int unlock(string str) {
    if(!str || str != "pedistal") {
	write("Unlock what?\n");
	return 1;
    }
    if(!present("demon_event_key_pedistal", this_player())) {
	write("You do not have a working key for the pedistal.\n");
	return 1;
    }
    if(!lock) return notify_fail("The book is already unlocked from "
	  "the pedistal.\n");
    write("The lock clicks and opens.  The key sticks into the "
      "pedistal.\n");
    if(present("demon_event_key_pedistal", this_player()))
	present("demon_event_key_pedistal", this_player())->remove();
    lock = 0;
    return 1;
}

int take(string str) {
    if(!str || str != "book") return notify_fail("Take what?\n");
    if(lock) {
	write("The book is locked on the pedistal.\n");
	return 1;
    }
    write("You take the book from the pedistal.\n");
    new("/d/events/obj/book")->move(this_player());
    say(this_player()->query_name()+" takes the book from the pedistal.");
    message("environment", "The pedistal sinks into the ground making an exit "
      "out of the room.", environment(this_player()) );
    environment(this_player())->add_exit("/d/events/rooms/1", "down");
    this_object()->remove();
    return 1;
}

