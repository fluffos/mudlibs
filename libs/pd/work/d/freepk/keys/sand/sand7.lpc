#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Northern end of a sandbar");
   set_long("This is the northern tip of the sandbar. The sand sinks "
	"gradually into the ocean, until no dry surface area is left. "
	"There are crab trails everywhere.");
   set_items(([
   ]));
   set_exits(([
	"south" : "/d/freepk/keys/sand/sand6"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab2");
     make("/d/freepk/keys/sand/crab2");
     make("/d/freepk/keys/sand/crab2");
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/qcrab");
   }
}
