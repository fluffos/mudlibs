#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Beached on the Great Sandbar");
   set_long("Cold surf sprays up off the millions of grains of sand that "
	"make up this sandbar, sending salt water into the air. Though "
	"it is quite perilous, the Great Sandbar has a peaceful and dull "
	"quite about it.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand4",
	"northwest" : "/d/freepk/keys/great_sand/sand6"
   ]));
}
void reset() {
 ::reset();
   if (!present("sandcrab"))
     new("/d/freepk/keys/great_sand/sandcrab")->move(this_object());
}

