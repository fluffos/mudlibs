// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;
void reset() {
::reset();
if(!present("hawk"))
new(MON2"hawk")->move(this_object());

}

void create() {
::create();
set_name("deep in the forest");
set_long("The path becomes very dark making it hard to see much.  There is still yet enough "
"light filtering through the treetops to show the way.  Trees surround both sides of the path.  "
"Several footprints can be seen also from the filtering light of small animals.  There is a small "
"sleeping area away from the path to the east.  Unaccesible from the path.");
set_properties(([
"light" : 1,
"forest" : 1,
]));

set_items(([
"path" : "It is dark and hard to see.",
(({"tree", "trees"})) : "The trees surround most of the path.",
(({"footprints", "footprint"})) : "There are many of them made from a small creature.",
(({"sleeping area", "area"})) : "The sleeping area is nothing but branches and small trees "
"laying over from an animal sleeping on it.",
]));
set_exits(([
"north" : ROOM2"16",

]));

}
