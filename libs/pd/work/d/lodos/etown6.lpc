#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("On a path leading east");
    set_property("light", 2);
    set_properties(([ "town" : 1 ])); 
    set_long("This is a small shack. Smoke "
      "pours forth from the shack to the south. The dirt road leads both "
      "to the east and to the west from here.");
    set_items(([
	"shack" : "The shack is to the south.",
	"road" : "An old dirt path.",
	"smoke" : "The smoke is comming out of the shack's chimney in billows."
      ]));
    set_exits(([ "west" : ROOMS"etown5",
	"south": ROOMS"fshack",
	"east" : ROOMS"etown7" ]));
}
