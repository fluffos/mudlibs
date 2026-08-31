//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a cave");
    set_short("a cave");
    set_long("Darkness seems to be everywhere.  The only light source is "
      "from the light at the entrance of the cave.  Jagged rocks "
      "line the entrance.  The hallways of the cave stretch "
      "further into the black abyss.");
    set_items(([
	({"jagged rocks", "small jagged rocks"}):"They protrude from the "
	"top of th cave forming the 'Teeth of the Dragon'",
      ]));
    set_exits(([
	"out":DEN"1",
	"west":DEN"3",
 "north":DEN"18",
      ]));
    set_properties((["light":1,"night light":1,"cave":1,"indoors":1,]));
}

