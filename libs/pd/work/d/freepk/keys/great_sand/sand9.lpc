#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The Great Sandbar");
   set_long("Sand expands in a bar going southeast and northwest. This "
	"sandbar is called by sailors the devil's arm, the death of many "
	"a foul-mouthed sailor.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand8",
	"northwest" : "/d/freepk/keys/great_sand/sand10"
   ]));
}
void reset() {
 ::reset();
   if (!present("sandcrab")) {
     new("/d/freepk/keys/great_sand/sandcrab")->move(this_object());
     new("/d/freepk/keys/great_sand/sandcrab")->move(this_object());
   }
}

