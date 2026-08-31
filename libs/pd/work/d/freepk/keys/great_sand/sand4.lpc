#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Beached on the Great Sandbar");
   set_long("This mass of sand in the ocean has been the downfall of "
	"many a great ship. Sharp rocks line the edge of the grainy, "
	"yet smooth, cool, wet sand.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand3",
	"northwest" : "/d/freepk/keys/great_sand/sand5"
   ]));
}

void reset() {
 ::reset();
   if (!present("seagull"))
     new("/d/freepk/keys/great_sand/seagull")->move(this_object());
}
