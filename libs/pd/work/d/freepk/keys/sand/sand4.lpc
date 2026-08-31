#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Atop a sandbar");
   set_long("Sand, sand, and more sand! Can you believe it?! Jeeez, "
	"where do these sandbars come from anyway.. and these crabs? "
	"What is this? Some kind of crab haven, or what? Does anybody "
	"even read these descriptions?");
   set_items(([
   ]));
   set_exits(([
	"south" : "/d/freepk/keys/sand/sand3",
	"north" : "/d/freepk/keys/sand/sand5"
   ]));
}

void reset() {
 ::reset();
   if (!present("crab")) {
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab");
     make("/d/freepk/keys/sand/crab");
   }
}
