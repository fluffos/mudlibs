#include <std.h>
#include <cp.h>
inherit ROOM;


void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 0, "mountains" : 1, "town" : 1]) );
  set_short("Gem Street - Steel Hammer Village");
  set_long(
   "Gem Street runs north and south. A well kept armoury "
   "stands on the west side of the road. A small gust "
   "of wind blows down the street, causing leaves to "
   "dance on the ground. To the east, a tall unclimbable "
   "mountain stands, preventing any passage.");
  set_items(([
    "mountain" : "The mountains stretch in all directions. They "
    "surround the small village. ", 
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "leaves" : "The blowing wind causes some dry leaves to "
    "dance in the street.",
    "armoury" : "An armoury is built on the west side of Gem "
    "Street. A sign is hung outside next to the open "
    "door.",
    "sign" : "Steel Hammer Armory"
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "Clanging metal can be heard in the distance.");
  set_exits( ([ 
    "north" :  ROOMS "s_gem1",
    "south" :  ROOMS "s_gem3",
    "enter armoury" :  ROOMS "armoury"]));

}
