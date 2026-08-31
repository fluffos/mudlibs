#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Inside Tenebrae");
  set("long","Once inside the city, the streets head "
    "east, toward the merchant district, or north and south, towards "
    "more residential areas. ");
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","The faint sound of merchants hawking their wares can be heard to the east.");
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads north, east, and south.",
    "path":"The path is dry and worn.",
    "stone":"The cobblestones are black and grey.  Like the sky."]));
  set_exits((["north":ROOMS "tene01","east":ROOMS "tene08",
    "gates":ROOMS "gate","south":ROOMS "tene04"]));
}

void reset() {
  ::reset();
  if(!present("shadowguard")) new(MOB "shadowguard")->move(this_object());
}
