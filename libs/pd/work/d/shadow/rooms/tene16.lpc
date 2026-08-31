#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Shack");
    set("long","From the outside, this building appeared to be "
      "a shop, but is somewhat deceitful.  This quaint home "
      "is currently occupied by an old adventurer from long ago."
      "  The room is covered with various artifacts and books of "
      "lore about the city of Tenebrae.");
    set_items(
      (["items":"Various trinkets with no apparent use.",
	"books":"The books are all old and falling apart."]) );
    set_exits( (["west" : ROOMS"tene17"]) );
}

void reset() {
    ::reset();
    if(!present("adventurer")) 
	new(MOB"adventurer")->move(this_object());
}
