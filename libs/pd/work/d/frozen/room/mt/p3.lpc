#include <std.h>
#include <frozen.h>

inherit ROOM;
int open;

void create() {
    ::create();
    set_name("a path up the mountain");
    set_short("a path in the snow");
    set_long("The path seems to stop, continueing would surely mean death.  "
      "there is a small indention in the snow.");
    set_exits(([
	"west":ROOMS"mt/p2",
	//        "east":ROOMS"mt/p3",
	//        "up":ROOMS"mt/p",
      ]));
    set_items(([
	({"mountain", "mountain peak", "peak"}):"The mountain peak is covered with snow.  "
	"It looks like an avalanche could happen at any moment.",
	({"path", "paths"}):"The path seems very dangerous.",
	"indention":"Perhaps you could put your hand in the indention.",
      ]));
}

void reset() {
    ::reset();
    open=0;
    remove_exit("cave");
}

void init() {
    ::init();
    add_action("put_hand", "put");
}

int put_hand(string s) {
    if(!s || s != "hand in indention") return notify_fail("Put what in where?\n");
    if(open) return notify_fail("Nothing happens.\n");
    write("There was a button in the indention.  Before you, a huge "
      "doorway opens, showing an entrance to a cave.");
    say("You hear a rumble as a huge door opens, showing the entrance to a cave.\n");
    add_exit(ROOMS"mt/cave1/1", "cave");
    open=1;
    return 1;
}

