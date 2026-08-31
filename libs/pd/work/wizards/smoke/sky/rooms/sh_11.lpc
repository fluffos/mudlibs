#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Platinum Street - Steel Hammer Village");
  set_long(
   "Platinum Street continues east and west. A mountain "
   "face is ahead to the east, meaning the road is almost "
   "at an end. A large monastery is just to the west "
   "and the House of Teleportation to the south. "
   "Dwarves can be seen hustling around "
   "doing whatever it is that they do. Large mountains "
   "totally surround the village.");
  set_items(([
    "mountains" : "The mountains stretch in all directions. They "
    "surround the small village. ",
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "dwarves" : "Lots of small dwarves are running through "
    "the village.",
    "monastery" : "It's farther west.",
    "house of teleportation" : "This building is home to a magical "
    "portal. It is on the southern side of the road.",
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "west" :  ROOMS "sh_10",
    "enter house" : ROOMS "tele",
    "east" :  ROOMS "sh_12"]));
}
