#include <std.h>
#include <cp.h>
inherit ROOM;


void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 0, "mountains" : 1, "town" : 1]) );
  set_short("Gem Street - Steel Hammer Village");
  set_long(
   "Gem Street runs north and south. A small, dingy "
   "looking building is on the western side of the "
   "street and the door is open. A loud clanging is "
   "coming from within the building. A tall, unclimbable "
   "mountain stands tall, preventing any passage.");
  set_items(([
    "mountain" : "The mountains stretch in all directions. They "
    "surround the small village. ", 
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "building" : "A small stone building is here. A sign is "
    "hanging above an open door.",
    "sign" : "%^BOLD%^%^CYAN%^     Grogg Stonebeard\n"
    "%^BOLD%^%^BLACK%^Village Senior Blacksmith%^RESET%^"
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "Metal clanging against metal can be heard "
   "from inside the blacksmith's shop.");
  set_exits( ([ 
    "north" :  ROOMS "sh_12",
    "south" :  ROOMS "s_gem2",
    "enter smithy" :  ROOMS "bsmith"]));

}
