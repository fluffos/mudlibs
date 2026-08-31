#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
   ::create();
   set_name("a path in the snow");
   set_short("a path in the snow");
   set_long("Mist covers most of the path, making it hard to see where the path "
      "leads.  Large footprints are imprinted on the path.");
   set_exits(([
      "southeast":ROOMS"snow3",
     "northwest":ROOMS"sl2",
      ]));
    set_properties(([
       "no teleport":1,
       "snow":1,
       ]));

}

