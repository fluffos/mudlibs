#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Atop a sandbar");
   set_long("The sandbar leads both north and south, a shipwreck waiting "
	"to happen.");
   set_items(([
   ]));
   set_exits(([
	"south" : "/d/freepk/keys/sand/sand2",
	"north" : "/d/freepk/keys/sand/sand4"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab2");
     make("/d/freepk/keys/sand/crab2");
   }
}
