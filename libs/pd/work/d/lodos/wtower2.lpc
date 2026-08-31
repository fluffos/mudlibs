#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The foot of a tower");
   set_properties((["light" : 2, "night light" : 1, "indoors" : 1]));
   set_long("The stairs lead almost straight up and down up through the "
      "tower. The round tower sprouts up, close to the clouds. Windows "
      "let light in and show the street below.");
   set_exits(([ "up" : ROOMS"wtower3",
                "down" : ROOMS"wtower1"]));
   set_items(([
      "stairs" : "They are almost vertical, they are so steep.",
      "tower" : "It touches the sky.",
      "windows" : "You can see the dirt path below through the windows."
   ]));
}
