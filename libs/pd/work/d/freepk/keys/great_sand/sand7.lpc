#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Beached on the Great Sandbar");
   set_long("Even despite it's gargantua size for a sandbar, the Great "
	"Sandbar becomes tiny when compared to the vast ocean "
	"surrounding it. The sandbar continues southeast and northwest.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand6",
	"northwest" : "/d/freepk/keys/great_sand/sand8"
   ]));
}

void reset() {
 ::reset();
   if (!present("seagull")) {
     new("/d/freepk/keys/great_sand/seagull")->move(this_object());
     new("/d/freepk/keys/great_sand/seagull")->move(this_object());
   }
   if (!present("sandcrab"))
     new("/d/freepk/keys/great_sand/sandcrab")->move(this_object());
}
