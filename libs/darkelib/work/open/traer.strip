#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The Blue Dragon Inn foyer");
    set("long",
	"This is the foyer of the inn.  You see hallways leading "+
	"to the south, east, and west.  To the north is the front "+
	"desk.  You see a staircase leading up.");
    add_exit("/d/damned/inn/main_room", "north");
    add_exit("/d/damned/inn/foyer2", "up");
    add_exit("/d/damned/inn/hall_10", "west");
    add_exit("/d/damned/inn/hall_11", "south");
    add_exit("/d/damned/inn/hall_12", "east");
    return;
}

