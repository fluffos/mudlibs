#include <std.h>
#include <discastle.h>
inherit ROOM;
void create()
{
    ::create();

    set_properties
    (
      (["light" : 2, "night light" : 1, "road" : 1])
    );
    set_short("Road to Distopia.");
    set_long
    (
      "The road takes a sharp turn here, to the east is what appears to be a building, "
      "not quite sure where one is is rather disconcerting, perhaps the building to the east "
      "has someone that can give directions? The tall spires of the castle peek over the woods "
      "to the north while the raised dias, still clearly visible, is south."
    );

    set_items
    (
      ([
	"castle" : "It looks beautiful",
	"spire" : "They are so huge",
	"dias" : "It's so strange. You can't get over it",
	"building" : "It is just a shape in the distance, however it clearly isn't anything but a building."
      ])
    );
    set_exits
    (([
	"east" : ROOMS"npath4",
	"south" : ROOMS"npath2"
      ]));
}
