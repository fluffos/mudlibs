#include <std.h>
inherit ROOM;
void create() {
::create();
set_name("Trophy room");
set_long("This is a large room.  Many fine treasures line the walls "
"and floors.  There is a large case of trophies to the north.  You "
"can see who has trophies by typing <list>.  There are many things "
"still missing but contruction of the building has not yet been "
"completed.");
set_exits(([
"east" : "/d/tirun/sveros1",
]));
set_properties(([
"light":1,
"night light":1,
"indoors":1,
]));
}
void reset() {
::reset();
if(!present("trophy case"))
new("/d/tirun/whit/case")->move(this_object());
}
void init() {
::init();
add_action("list", "list");
}
int list() {
if(!present("trophy case")) return notify_fail("There isnt a trophy case.\n");
write("There aren't any trophies yet.\n");
return 1;
}
