
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("A Wasteland");
set_day_long("You are closer to the mainland. More dead soldiers are sighted. This tiny piece of land that sticks out in the north for the docks leads south to where the major battle is still being fought. You see smoke and the parapets of a huge castle in the distance. ");
set_night_long("You walk further south in the moonlight. Fortunately, you can find your way around this area with ease. Dead and wounded soldiers of this war litter the area. This narrow piece of land connects to the mainland where the major battle is being fought. You see a glowing light in the forest to the south and you make out the silhouette of the immense castle in the moonlight.");
set_items(([
"soldiers" : "Dead and wounded, they are ignored.",
"castle" : "A huge castle in the distance.",
"smoke" : "Seems like there's a base set up in the forest.",
"light": "A light glows in the forest. It is as if someone started a bonfire in Burham Woods",
]));
set_smell("default","The smell of fresh blood and corpses fill the air.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_properties((["light" : 1, "night light" : 0,]));
set_exits( ([ "south" : "/wizards/powerman/room/pathc",
              "north" : "/wizards/powerman/room/patha"]));
}
