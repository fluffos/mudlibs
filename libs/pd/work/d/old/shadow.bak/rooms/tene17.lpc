#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","First Street");
  set("long","This is First Street which passes a variety of businesses "
    "that line the east and west sides of this street.  "
    "There is a sign here with directions on it.  People here "
    "bustle about, minding their own business.  There are 2 shops that are"
    "open here to the east and west.");
  set_smell("default","The smell of baked goods permeates the air.");
  set_listen("default","The din of merchants hawking their wares can be heard.");
       set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road
     heads north, east, and south.",
    "path":"The path is dry and worn.",
    "people":"The people here are white from the lack of a normal amount of
sunlight.",
    "stone":"The cobblestones are black and grey.  Like the sky."]));
  set_exits((["south":ROOMS "tene11","east":ROOMS "tene16","west":ROOMS "tene18"]));
}
