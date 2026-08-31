#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The northeastern tip of the Great Sandbar");
   set_long("This is the northeastern tip of the devil's arm, the Great "
	"Sandbar. This strip of saltly sand has been the demise of many "
	"seamen. The sandbar leads southeast.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand11",
   ]));
}

void reset() {
 ::reset();
   if (!present("seagull"))
     new("/d/freepk/keys/great_sand/seagull")->move(this_object());
}

