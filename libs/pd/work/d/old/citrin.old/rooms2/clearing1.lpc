// Coded by Whit

#include <citrin.h>
#include <std.h>

inherit ROOM;
int rt;
void init() {
::init();
}

void reset() {
::reset();
rt = 1;
}

int search(string str) {
if(rt==0) return notify_fail("You find nothing.");
if(!str) return notify_fail("You don't find anything");

write("You find a small tracker!");
new("/d/citrin/objects2/tracker")->move(this_player());
rt=0;
return 1;
}


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
"north" : ROOM2"15",
"south" : ROOM2"clearing2",
"west" : ROOM2"error"
]))
;
}
