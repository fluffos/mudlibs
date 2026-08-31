#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In the crow's nest");
   set_long("The crow's nest of the ship is high enough up that the "
	"entire sandbar below can be seen. This is where the lookout "
	"would watch the horizon for land. The crows nest is "
	"constructed of wooden planks nailed into the shape of a nest.");
   set_items(([
	"sandbar" : "Not much interesting down there..",
	"planks" : "Securely fastened down."
   ]));
   set_exits(([
	"down" : "/d/freepk/keys/great_sand/wreck"
   ]));
}

void reset() {
   if (!present("watch"))
     new("/d/freepk/keys/great_sand/watch")->move(this_object());
}
