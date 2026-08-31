#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The Great Sandbar");
   set_long("Just to the northwest is the tip of the Great Sandbar. Sand "
	"leads northwest and southeast along this long strip of sand.");
   set_items(([
   ]));
   set_exits(([
	"southeast" : "/d/freepk/keys/great_sand/sand10",
	"northwest" : "/d/freepk/keys/great_sand/sand12"
   ]));
}

void reset() {
 ::reset();
   if (!present("seagull")) {
     new("/d/freepk/keys/great_sand/seagull")->move(this_object());
     new("/d/freepk/keys/great_sand/seagull")->move(this_object());
   }
}

