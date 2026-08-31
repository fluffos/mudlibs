#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("A Wasteland");
set_day_long("All the dead bodies that litter the ground made you forget the woods that lie about a mile ahead of you. You can now see more of the towers of the castle in the distance. The smoke in the forest still prevails. You sense that this area used to be very beautiful. ");
set_night_long("The moonlight is reflected off the swords of those who were slain. Most swords being blood stained you see the reflections of many blood moons. You remember that there was a forest ahead, but you cannot see it in this moonlight. The parapets of the castles covers a part of the moon.");
set_items(([
"soldiers" : "Dead and wounded, they are ignored.",
"castle" : "A huge castle in the distance.",
"smoke" : "Seems like there's a base set up in the forest.",
"light": "A light glows in the forest. It is as if someone started a bonfire in Burham Woods",
]));
set_smell("default","The smell of fresh blood and corpses fill the air.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_properties((["light" : 1, "night light" : 0,]));
set_exits( ([ "south" : "/wizards/powerman/room/pathd",
              "north" : "/wizards/powerman/room/pathb"]));
}
