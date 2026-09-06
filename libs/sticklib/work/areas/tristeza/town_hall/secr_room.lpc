#include <room.h>

#include "DEFS.h"
void
create_room()
{
    set(IN_CITY);
    set(NO_PK);
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Secretary's room");
    set_long(
      "You see a desk full of papers and other materials, though neatly stacked.\
 The walls are covered with bookcases and file cabinets. You therefore\
 conclude that this must be the room for the mayor's secretary.");
    set_exits(([
	"north"	: THALL_ROOMS "mayors_off",
	"east"	: THALL_ROOMS "hall",
      ]));
    set_items(([
	"papers" : "They look very important.",
	"bookcases" : "They are full of dusty books.",
	({"books","dusty books"}) : "They are just some old dusty books.",
	({ "cabinets", "file cabinets" }) : "They are locked."
      ]));
    add_monster(THALL_NPC "secretary", "Secretary arrives.", 1);
}
