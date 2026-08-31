#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","South Alley");
  set("long","This alley heads south amongst a variety of houses.  "
    "The houses are all grey with old shingles on top.  The houses "
    "look like they're really old. The wall of the city is on the right, "
    "and continues south.");
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","Conversation can be heard coming from a few houses.");
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads east, and south.",
    "house":"The house is old and run down.  You try the door, but it is locked.",
    "wall":"The wall to the city is old and is growing a bit "
      "of %^GREEN%^moss%^WHITE%^, but still intact.",
    "moss":"What a cute little plant!",
    "stone":"The cobblestones are black and grey.  Like the sky."]));
  set_exits((["north":ROOMS "first","south":ROOMS "tene05"]));
}
