#include <std.h>
#include <sindarii.h>

inherit ROOM;


void create() {
  ::create();
    set_property("light", 2);
    set_property("forest", 1);
    set("short", "The jungle");
    set("long",
        "The forest is ever increasing in humidity. "
	"The vegetation that imposes itself upon you from "
	"every direction becomes even thicker to the north and east. "
	"It looks a bit tamer as you look south and west.");
    set_items(
	(["jungle" : "A growing rain forest full of green vegetation.",
	  "vegetation" : "All sorts of plant life growing as you have "
	  "never before seen."]) );
    set_exits( 
	      (["northeast" : ROOMS "rain_forest",
                "southeast" : "/d/nopk/forest/forest10"]) );
}
