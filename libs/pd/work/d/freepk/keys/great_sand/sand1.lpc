#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Beached on the Great Sandbar");
   set_long("The sandbar continues both southeast and northwest. There "
	"is lumber and other shipwreck debris lying around here on the "
	"sand. Cool ocean waves wash onto the sand.");
   set_items(([
     "hole" : "It would be a tight squeeze, but you could fit into it."
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/beach",
	"northwest" : "/d/freepk/keys/great_sand/sand2"
   ]));
}

int enter(string str) {
   if (!str || str == "") return 0;
   if (str != "hole" && str != "wreckage") return 0;
   this_player()->move_player("/d/freepk/keys/great_sand/wreck", "wreckage");
   return 1;
}

void init() {
 ::init();
   add_action("enter", "enter");
}

void reset() {
   if (!present("wreckage"))
     new("/d/freepk/keys/great_sand/wreckage")->move(this_object());
}
