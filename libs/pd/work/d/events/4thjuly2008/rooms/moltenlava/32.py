#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "no teleport" : 1, "night light" : 1]) );
set_smell("default", "The tunnel has a smokey, burning smell to it.");
set_listen("default", "The bubbling of lava can be heard throughout the tunnels.");
set_short("venturing through tunnels");
set_long("The molten tunnels are %^RED%^%^BOLD%^flaming%^%^RESET%^ hot, and hard to see through with all the light. %^BOLD%^%^BLACK%^Bats %^RESET%^fly throughout the tunnels, screeching occasionally. Stalagmite and stalactite make the tunnel look as if it is a mouth filled with fangs. A %^BOLD%^%^BLACK%^black%^RESET%^ rock falls from the ceiling, causing a %^BOLD%^splash%^RESET%^ in the %^RED%^%^BOLD%^l%^RESET%^%^RED%^a%^YELLOW%^v%^BOLD%^a%^RESET%^ that carries throughout the tunnels.");
set_items(([
"lava" : "There is a pool of lava on either side of you.",
"smoke" : "Wisps of smoke float through the air..",
"ground" : "The ground beneath you is a very hot looking rock path, surrounded by pools of lava..",
({"rock", "rocks"}) : "The path below you is made of rocks..",
]));
set_exits(([ "northeast" : ROOMS "/moltenlava/31.c",
"northwest" : ROOMS "/moltenlava/33.c",
"southwest" : ROOMS "/moltenlava/34.c"]));
}

void reset() {
::reset();
if (!present("ogre")) {
new(MOBS+"ogremage")->move(this_object());
}
}

