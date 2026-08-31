#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Atop a sandbar");
   set_long("The southern tip of this sandbar is mostly submerged in "
	"the salty ocean water. A strong breeze blows wet sand across "
	"the sandbar.");
   set_items(([
   ]));
   set_exits(([
	"north" : "/d/freepk/keys/sand/beach"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab");
   }
}
