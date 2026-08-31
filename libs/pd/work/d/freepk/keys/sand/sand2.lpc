#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Atop a sandbar");
   set_long("This is a fairly long sandbar, enough of one to be quite "
	"a hazard to a boat sailing along in the ocean. Water washes "
	"onto the sand, wetting it.");
   set_items(([
   ]));
   set_exits(([
	"south" : "/d/freepk/keys/sand/sand1",
	"north" : "/d/freepk/keys/sand/sand3"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab");
   }
}
