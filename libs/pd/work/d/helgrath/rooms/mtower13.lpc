#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
	"light" : 2,
      ]));
    set_short("Mage Tower");
    set_long("This empty room seems to be an old storage area for books, recently cleaned out.  "
      "A thin layer of dust blankets the room, and no mages seem to come back here.  Some small "
      "papers lie on the the floor, off to one side.  This room is a little bit darker than the "
      "others.");
    set_exits( ([ "southwest" : ROOMS "mtower14",
	"southeast" : ROOMS "mtower12" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
	"dust" : "The dust is thinly layered over everything, indicating that this room is rarely used.",
	"papers" : "Some notes about how the back room in the library needs to be cleaned."
      ]));
}
