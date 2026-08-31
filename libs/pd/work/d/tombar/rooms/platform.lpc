// Coded by Whit

#include <std.h>
#include <tombar.h>

inherit ROOM;

void init() {
    ::init();
    add_action("jump", "jump");
}
int rt;
void create() {
    ::create();
    set_name("a room with a fountain");
    set_long("The platform doesnt bend from the wait of your body.  "
      "The magic is strong enough to hold almost anything.  There is "
      "no railing here to protect someone from falling off.  The whole "
      "room can be seen from here.  For some unseen force you cannot "
      "see who is in the room.  The fountain below can be seen from the "
      "side of the platform.");

    set_listen("default", "The sound of dripping water is near.");
    set_smell("default", "There is a stale smell in this room.");
    set_exits(([
	"down" : ROOMS"3",
      ]));
    set_items(([
	(({ "walls", "wall" })) : "The walls are damp and musty from the "
	"constant exposure to moisture.",
	"ceiling" : "Water drips into the fountain feeding it with water.",
	"fountain" : "The fountain can be seen below here.  It may be dangerous "
	"but you may be able to jump into the fountain.",
	"platform" : "The platform hovers magical over the fountain.",
	"ladder" : "The ladder leads down to the floor.  It looks steep "
	"and hard to climb.",
      ]));

}

void reset() {
    ::reset();
    rt=1;
}

int jump(string str) {
    if(!str) return notify_fail("Jump what?\n");
    if(str != "fountain") return notify_fail("Jump what?\n");
    if(this_player()->query_level() < 50 ) {
	write("You are too small to fall to your death!");
	return 1;
    }
    if(rt==0) return notify_fail("You are too scared to jump!");
    write("If you are sure you want to end your life already.");
    this_player()->move_player(ROOMS"fake_death");
    say(this_player()->query_name()+" disappears off the side of the platform.");
    rt=0;
    return 1;
}
