#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("inside", 1 );
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^You have entered the room, and noticed right away that the giant Guardians face, on the gate infront of you, is missing its right eye.  Looking beyond the gate, you see an enormous pyramid.%^RESET%^\n");
    set_items( ([ "gate": "%^BOLD%^%^YELLOW%^This gate is made with pure steal except for the Magi Guardians face, which is made of a golden stone.", "face": "The face is giant, but seems to be missin a right eye.  Maybe, if you had the eye and inserted it, you could pass." ]) );
    set_exits( ([ "south" : ROOMS+"guardians_room" ]) );
    add_pre_exit_function("gate", "go_gate");
    new(MARSHARM+"guardians_gate")->move(this_object());
}
void init() {
    ::init();
    add_action("insert_eye", "insert");
}
int go_gate() {
    if (!present("guardians gate")) {
	return notify_fail("The gate blocks your way!\n"); 
    }
    else {
	return 1; }
}
int insert_eye(string str) {
    if (!present("guardians eye", this_player())) {
	return notify_fail("You don't have the eye!\n");
    }
    if (!str || str != "eye") {
	return notify_fail("Insert what?\n");
    }
    write("You insert the eye into the gate.");
    write("The gate swings open.");
    add_exit(ROOMS+"entrance1", "gate");
    return 1;
}
