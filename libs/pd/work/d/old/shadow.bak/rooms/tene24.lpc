#include <std.h>
#include <shadow.h>
inherit ROOM;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Main Street");
  set("long","This is Main Street which leads to the Palace, while the square is to the west.  "
    "The palace here is huge, towering skyward.  The doors here are open"
    " and the light inside is a welcome break from the city's darkness.");
  set_smell("default","The smell of baked goods wafts in from the west.");
  set_listen("default","The din of merchants hawking their wares can be heard to the west.");
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads west, and into the palace.",
    ({"house","houses"}):"The house is old and run down.  You try the door, but it is locked.",
    "stone":"The cobblestones are black and grey.  Like the sky.",
    "palace":"The palace looms upward, a black shillouette against a dark sky."]));
  set_exits((["enter":ROOMS "palace01","west":ROOMS "tene15"]));
}
 
void reset() {
  ::reset();
  if(!present("shadowguard")) {
    new(MOB "shadowguard")->move(this_object());
    new(MOB "shadowguard")->move(this_object());
  }
}
