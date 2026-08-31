#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 0, "night light" : 0]) );
set_smell("default", "The tunnel has a stagnant, stale stench to it.");
set_listen("default", "Echos near and far can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The dark tunnels steer in many directions, hopelessly leading to nowhere. The ground is covered in jagged stones of different sizes, scattered randomly throughout the dirt. There is a strong sense of stagnancy here. Footprints can be seen below, heading in all directions. Specks of dirt float through the air, sticking to any sort of sweat or moisture.");
set_items(([
"dark" : "Although you can't see it, the darkness is very dark.",
"dirt" : "The dirt of the tunnels floats through the stagnant air.",
"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
]));
set_exits(([ "northwest" : ROOMS "/darkandscary/12.c",
"west" : ROOMS "/darkandscary/15.c",
"east" : ROOMS "/darkandscary/17.c"]));
}
