#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Main Street");
  set("long","This is Main Street which runs east and west past a variety of houses.  "
    "They line the north and south sides of this street as it approaches the palace.  "
    "The Square is to the west, and the Palace looms ahead to the east.");
  set_smell("default","The smell of baked goods wafts in from the west.");
  set_listen("default","The din of merchants hawking their wares can be heard to the west.");
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads east, and south.",
    ({"house","houses"}):"The house is old and run down.  You try the door, but it is locked.",
    "stone":"The cobblestones are black and grey.  Like the sky.",
    "palace":"The palace looms ahead, a black shillouette against a dark sky."]));
  set_exits((["east":ROOMS "tene24","west":ROOMS "tene10"]));
}
