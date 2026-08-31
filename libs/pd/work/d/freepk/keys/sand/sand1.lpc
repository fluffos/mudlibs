#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Atop a sandbar");
   set_long("The sandbar lowers a bit to the south and continues for "
	"a few meters north. Ocean water sprays onto the sandbar, a "
	"treacherous trap for boats.");
   set_items(([
   ]));
   set_exits(([
	"south" : "/d/freepk/keys/sand/beach",
	"north" : "/d/freepk/keys/sand/sand2"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab");
   }
}
