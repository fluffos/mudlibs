// Coded by Whit

#include <citrin.h>
#include <std.h>

inherit ROOM;


void create() {
::create();
set_name("a small clearing");
set_long("This is a small clearing in the middle of the forest.  "
"unlike the rest of the wood there are no trees here.  There grass "
"has been matted down making it a possible place where game sleep.  "
"Something glistens under the grass.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1, ]));

set_items(([
"grass" : "It has been matted down making it a possible place for game "
"to sleep.",
]));

set_exits(([
"north" : ROOM2"clearing1",
"south" : ROOM2"clearing3",
"west" : ROOM2"error"
]))
;
}
