#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 1);
    set("short", "In a tunnel within the daroq caves");
    set("long",
        "The tunnel passage leads up and down through the rock of the "
        "Daroq Mountain. A short climb upwards reveals the opening to "
        "the outside. Light shines in from the opening above.");
    set_exits(([ "up" : ROOMS"daroq/cave9",
                 "down" : ROOMS"daroq/cave7" ]));
}

void reset() {
 ::reset();
   if (!present("tak'daroq"))
      new(MOB"takdaroq")->move(this_object());
}
