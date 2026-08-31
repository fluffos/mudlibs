//  Whits House

#include <std.h>
#include <daemons.h>

inherit ROOM;

int open;

void create() {
    ::create();
    set_name("whits house");
    set_short("Whit's House");
    set_exits(([ "out":"/wizards/whit/workroom" ]));
    open=0;
}

string query_long() {
    if(!open)
	return "The house seems a bit, small.  No furnishings of "
	"anytype exist in the house.  A carpet lays in the middle "
	"of the floor.  A cool breeze comes from under the carpet.";
    return "The house seems a bit, small.  No furnishings of "
    "anytype exist in the house.  The carpet has been pushed "
    "out of place revealing a trap door.";  
}

void init() {
    ::init();
    add_action("down", "down");
    add_action("push", "push");
}

int down() {
    if(!open) return 0;
    this_player()->move_player("/wizards/whit/house/room1", "down");
    return 1;
}

int push(string s) {
    int tmp, str;
    if(!s || s != "carpet") return 0;
    if(open) return notify_fail("The carpet has already "
	  "been pushed out of the way.");
    str=this_player()->query_stats("strength");
    tmp=random(str)-(this_player()->query_level()*2);
    if(tmp > this_player()->query_level()) {
	write("You push as hard as you can, but fail to move the carpet.");
	say(this_player()->query_cap_name()+" attempts to move the carpet, "
	  "but is unsecessful.\n");
	return 1;
    }
    write("You push the carpet out of the way revealing a trap door.\n");
    say(this_player()->query_cap_name()+" moves the carpet revealing "
      "a trap door.\n");
    open=1;
    return 1;
}

void reset() {
    ::reset();
    if(open) message("", "By some unknown force, the carpet "
	  "returns back to its place.", this_object());
    open=0;
}

