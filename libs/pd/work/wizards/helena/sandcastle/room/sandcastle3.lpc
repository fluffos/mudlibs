#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 3, "night light" : 2, "indoors" : 1]) );
set_short("East Room");
set_long("You have entered the east front room of this sandcastle. This side of the castle is less stable, cracks in the walls and ceiling quite visible. There are exits to the west and north.");
set_items((["room" : "This room is quite unstable, and badly made. It could collapse at any time it seems.", "ceiling" : "One touch of the ceiling and the whole thing would cave in.", "floor" : "The sand here is more muddy than the rest of the castle, acting like sloppy quicksand and slowly sinking your toes in, but not dangerously.", "walls" : "Large cracks in the walls lead you to believe that either someone was bad at making this, or its just really old."]));
set_smell("default", "Decay and death are heavy here, with a overlaying smell of fish.");
set_listen("default", "The Ocean seems even more distant now as the silence takes over this room.");
set_exits( (["west" : ROOMS "sandcastle1", "north" : ROOMS "sandcastle5"]) );
}

void reset() {
::reset();
if (!present("rubbish"))
new(MOB "rubbish")->move(this_object());
}
