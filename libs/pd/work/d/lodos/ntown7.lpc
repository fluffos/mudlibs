#include <lodos.h>
#include <std.h>
inherit VAULT;

void create() {
 ::create();
   set_properties((["town" : 1, "outdoors" : 1, "light" : 2 ]));
   set_short("On a dirt path between two towers");
   set_long("This dirt path leads north and south. The path has come "
      "directly between two rather large towers, one to the east and "
      "one to the west. Because of the two towers, the path here is "
      "pretty shady and comfortable during the day, and cold at night. "
      "Both the eastern and western towers have wooden doors attached "
      "to them.");
   set_items(([
      "path" : "The old dirt path leads north and south.",
      "towers":"There are two towers: one east and one west.",
      "shadows":"The path is covered in a long shadow here.",
      "doors":"Both of the tower's doors are wooden and small."
   ]));
   set_exits(([ "south" : ROOMS"ntown6",
                "north" : ROOMS"ntown8",
                "west" : ROOMS"wtower1",
                "east" : ROOMS"etower1"]));
   set_door("door", ROOMS"wtower1", "west", "");
   set_door("door", ROOMS"etower1", "east", "");
}
