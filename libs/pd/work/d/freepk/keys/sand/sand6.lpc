#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Atop a sandbar");
   set_long("The crabs seem to have adapted to this sandbar as a sort "
	"of haven. A thin ocean fog begins to gather just above the "
	"water.");
   set_items(([
   ]));
   set_exits(([
	"south" : "/d/freepk/keys/sand/sand5",
	"north" : "/d/freepk/keys/sand/sand7"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab2");
     make("/d/freepk/keys/sand/crab2");
   }
}
