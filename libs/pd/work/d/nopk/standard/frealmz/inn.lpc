// - Inferno -  The bread and board inn =) =) =)

#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside the walls of the bread and board inn");
   set_long("You have entered the front room of a "
            "small, two story inn. A winding staircase "
            "leads up to the second story, and a small "
            "doorway leads west. You are standing upon "
            "a beautiful polished wooden floor. A small "
            "reception desk stands at the far side of "
            "the room.");
   set_exits(([
      "out" : "/d/standard/frealmz/town5",
      "stairs" : "/d/standard/frealmz/stairs",
      "west" : "/d/standard/frealmz/west_inn"
   ]));
   set_items(([
      "floor" : "It adds a great touch to the inn",
      "staircase" : "It leads up to the second story."
   ]));
}

void reset() {
 ::reset();
   if (!present("desk"))
      new("/d/standard/frealmz/obj/desk")->move(this_object());
}
