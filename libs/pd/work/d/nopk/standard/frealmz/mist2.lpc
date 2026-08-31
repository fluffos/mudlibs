// - Inferno -

#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("path to a strange town");
   set_long("A thin mist covers the area, along with a strange "
            "magical feel. The air behind you seems to shimmer, "
            "as though in the desert heat. A small paved road "
            "leads east into a town.");
   set_exits(([
      "east" : "/d/standard/frealmz/town_ent"
   ]));
   set_items(([
      "road" : "It leads up to a strange looking town.",
      "town" : "It has a strange look to it, but you can't place "
               "what it is."
   ]));
}

void reset() {
 ::reset();
   if (!present("townsman"))
      new("/d/standard/frealmz/mob/townsman")->move(this_object());
}
