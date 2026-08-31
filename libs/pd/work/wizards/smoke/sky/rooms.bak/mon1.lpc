#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Steel Hammer Monestary");
  set_long(
   "A huge monastery is here. Steps lead down back to "
   "Platinum Street and a giant archway leads inside. "
   "The monastery is carved from the stone of the "
   "mountain. Large, stained glass windows line "
   "the walls.");
  set_items(([
    "monastery" : "A huge stone monastery stands tall here. It has "
    "has stained glass windows all around the perimeter. ",
    "windows" : "Colorful windows decorate the monastery.",
    "platinum street" : "Platinum Street is the main street in the "
    "village. It runs east and west and is usually very busy.",
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "steps" : "Tall stone steps lead back down to Platinum Street. "
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "enter monastery" :  ROOMS "mon2",
    "south" :  ROOMS "sh_10"]));
}
