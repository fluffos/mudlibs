#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Palace gatekeep%^RESET%^");
set_day_long("%^YELLOW%^You are at the gatekeep leading into the palace walls.  The Merkkirri Queen's palace lies within and she is not fond of visitors from the outside world.%^RESET%^");
set_day_long("%^YELLOW%^You are at the gatekeep leading into the palace walls.  The Merkkirri Queen's palace lies within and she is not fond of visitors from the outside world.%^RESET%^");
set_items(([
"gatekeep" : "The gatekeep is made of %^BOLD%^YELLOW%^gold%^RESET%^ as is the entire city.",
]));
set_properties((["light" : 2, "night light" : 2,]));
new(MJUNGLE "gatekeep.c")->move (this_object());
set_exits(([
"west": GCITY "gcity21.c",
"east": GCITY "gcity15.c",
]));
}

void reset() {
 ::reset();
if(!present("guard")) {
new(MOB "gnollguardb.c")->move (this_object());
new(MOB "gnollguardb.c")->move (this_object());
}
}
