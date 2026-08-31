#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels ruthlessly %^YELLOW%^%^BOLD%^boil%^RESET%^ and %^RED%^%^BOLD%^burn%^RESET%^ beneath the rocky path. A %^BOLD%^%^BLACK%^black%^RESET%^ rock falls from the ceiling, causing a %^BOLD%^splash%^RESET%^ in the %^RED%^%^BOLD%^l%^RESET%^%^RED%^a%^YELLOW%^v%^BOLD%^a%^RESET%^ that carries throughout the tunnels. Although there are no footprints on the ground, the walls seem to be chipped to let you know you aren't alone. The air is composed of a stiffling mixture of heat and sulfur. %^RED%^%^BOLD%^Fl%^YELLOW%^a%^RESET%^%^RED%^m%^BOLD%^es%^RESET%^ randomly sprout from the ground, putting themselves out over time.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "north" : ROOMS "/moltenlava/final.c",
"southeast" : ROOMS "/moltenlava/32.c"]));
}

void reset() {
::reset();
if (!present("ogre 5")) {
new(MOBS+"ogre")->move(this_object());
new(MOBS+"bigogre")->move(this_object());
new(MOBS+"ogrethug")->move(this_object());
new(MOBS+"ogremonk")->move(this_object());
new(MOBS+"greenogre")->move(this_object());
}
}

