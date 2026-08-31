#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Main Street");
  set("long","This is Main Street which passes a variety of houses.  "                "They line the north and south sides of this street.  "
    "The Merchant District approaches from the east, along with the Square"
    "and continues north.");
  set_smell("default","The smell of baked goods wafts in from the east.");
  set_listen("default","The din of merchants hawking their wares can be heard to the east.");
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads east, and south.",
    "house":"The house is old and run down.  You try the door, but it is locked.",
    "stone":"The cobblestones are black and grey.  Like the sky."]));
  set_exits((["east":ROOMS "tene10","west":ROOMS "first"]));
}
