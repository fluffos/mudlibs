// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("a small island");
set_long("The small island beach is made from white grains of sand.  "
"The sand glistens in the sun.  Several sea shells lay here opened "
"where the island inhabitants have eaten them.  Several coconut trees grow "
"by the shore.");

set_properties(([ "light" : 1, "night light" : 1, "island" : 1, ]));
set_items(([
"footprints" : "They belong to that of a drider",
]));
set_exits(([
"south" : ROOM2"island1",
"west" : ROOM2"island3",
"north" : ROOM2"island5",
]));



}

void reset() {
::reset();
if (!present("sand pixie"))
new(MON2"pixie")->move(this_object());

}
