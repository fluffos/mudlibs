inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Outside the gates of Tenebrae");
  set("long","The land here is dry and dark.  The wind blows in mightily "
    "from the sea.  The rocks to the north and south are impassible.  "
    "The dusty path weaves between the rocks to the east.  Not much is "
    "visible past them.  The pier is to the west.");
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","The wind is howling around you in this dark place.");
  set_items((["sky":"The sky is oppressively dark over the city.",
    "rocks":"They prevent movement to the north and south, and block vision to the east.",
    "path":"The path is dry and worn."]));
  set_exits((["east":ROOMS "gate","west":ROOMS "entrance"]));
}
