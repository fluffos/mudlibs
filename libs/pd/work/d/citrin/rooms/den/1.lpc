//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("a forest");
    set_long("The large mouth of a cave is here.  Nothing can be seen "
      "inside the huge dark mouth of the cave.  The cave is "
      "shaped in the shape of a dragon.  Rubies take the place "
      "of where the eyes are supposed to be.  Small jagged "
      "rocks protrude from the top of the cave.");
    set_items(([
	({"rubies","eyes"}):"They are the 'Eyes of the Dragon'",
	({"jagged rocks", "small jagged rocks"}):"They protrude from the "
	"top of th cave forming the 'Teeth of the Dragon'",
      ]));
    set_exits(([
	"enter":DEN"2",
	"east":ROOMS"17",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

