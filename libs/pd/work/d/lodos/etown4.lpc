#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("On a path leading east");
   set_property("light", 2);
   set_properties(([ "town" : 1 ]));
   set_long("Town square and the temple to Omicron lie to the west of "
      "here. The path leads east and west, but splits north here into "
      "a small cafe of some sorts. The cafe sends a shadow across the "
      "path, much like a tree.");
   set_items(([
      ({ "square", "temple" }) : "It can be seen to the west.",
      "path" : "The path leads two directions; east and west.",
      "cafe" : "It is the Golden Talon Cafe.",
      "shadow" : "The shadow covers this portion of the path."
   ]));
   set_exits(([ "west" : ROOMS"town3",
                "north": ROOMS"cafe",
                "east" : ROOMS"etown5" ]));
}

void reset() {
 ::reset();
   if (!present("citizen"))
      new(MOB"citizen")->move(this_object());
}
