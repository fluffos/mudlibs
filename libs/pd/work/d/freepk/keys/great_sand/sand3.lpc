#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Beached on the Great Sandbar");
   set_long("Sand streches southeast and northwest, forming the Great "
	"Sandbar. Some shells have been washed ashore by the fierce "
	"ocean waves.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand2",
	"northwest" : "/d/freepk/keys/great_sand/sand4"
   ]));
}
void reset() {
 ::reset();
   if (!present("sandcrab")) {
     new("/d/freepk/keys/great_sand/sandcrab")->move(this_object());
     new("/d/freepk/keys/great_sand/sandcrab")->move(this_object());
   }
}

