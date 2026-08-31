// Coded by Whit

#include <std.h>
#include <tombar.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a short, black hallway");
    set_long("Every foot step can be heard ringing throughout the cold, "
      "damp halls.  The stone walls are damp from the dripping water that "
      "leaks throught the ceiling.");
    set_listen("default", "The sound of dripping water is near.");
    set_smell("default", "There is a stale smell in this room.");
    set_exits(([
	"east" : ROOMS"2",
	"southwest" : ROOMS"3",
      ]));

    set_items(([
	(({ "walls", "wall" })) : "The walls are damp and musty from the "
	"constant exposure to moisture.",
	"ceiling" : "Water drips constantly from it.",
      ]));

}
