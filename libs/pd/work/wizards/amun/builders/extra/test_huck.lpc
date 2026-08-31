#include <paroth.h>
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Goblin entrance");
    set_long("A waterfall can be seen below. Most of Paroth can be seen from here. A extremely large oak tree can be seen in the distance.");
    set_property("no teleport",1);
    set_exits( ([ ]) );
}       
void init() {
    ::init();
    add_action("jump", "jump");
}
int jump(string str) {
    object tp;
    tp = this_player();
    if (str == "over cliff") {
	write("You jump off the cliff and head towards the sharp rocks below.");
	call_out("jump_delay", 10);
	this_player()->set_paralyzed(10);

	return 1;
    }
}

int jump_delay(object tp) {
    int sps;
    message("info", this_player()->query_cap_name()+" jumps over the cliff!", environment(this_player()), ({this_player()}) );
    message("info", "you feel like you're not gonna make and start to scream AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH!", environment(this_player()));
    this_player()->add_hp(-50);
    this_player()->move_player(ROOMS"waterfall_room");
    return 1;
}
