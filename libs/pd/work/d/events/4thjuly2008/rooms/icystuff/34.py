#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "no teleport" : 1, "no teleport" : 1, "light" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a fresh and frozen smell to it.");
set_listen("default", "Echos near and far can be heard throughout the chilly tunnels.");
set_short("venturing through icy tunnels");
set_long("The icy tunnels slip through many directions, sliding to nowhere. The air is composed of a fresh mixture of %^BOLD%^cold%^RESET%^ and clean. Large boulders of %^BOLD%^%^BLUE%^ice%^RESET%^ are being formed by the constant dripping of the ceiling. A large %^BOLD%^i%^RESET%^%^BLUE%^c%^RESET%^%^BOLD%^i%^CYAN%^c%^RESET%^%^BOLD%^l%^RESET%^e falls from the ceiling, causing a crash that carries throughout the tunnels. A blinding light reflects off of every icy surface.");
set_items(([
"ice" : "Whether the sheets, boulders of, or icicles - ice covers this entire area.",
"snow" : "The ground is covered in a thin layer of snow..",
"walls" : "The walls have an occasional torch, burning through blue ice to see blue rock.",
({"rock", "rocks"}) : "The rocks are all frozen, and have turned a bluish color.",
]));
set_exits(([ "east" : ROOMS "/icystuff/final.c",
"south" : ROOMS "/icystuff/33.c"]));
}

void reset() {
::reset();
if (!present("ogre 2")) {
new(MOBS+"ogre")->move(this_object());
new(MOBS+"ogremonk")->move(this_object());
}
}

