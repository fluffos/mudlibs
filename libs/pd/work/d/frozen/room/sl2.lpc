#include <std.h>
#include <frozen.h>

inherit ROOM;

void create() {
   ::create();
   set_name("a path in the snow");
   set_short("a path in the snow");
   set_long("Mist covers most of the path, making it hard to see where the path "
      "leads.  The footprints seem more numerous now.  There is hardly any spot "
      "on the path that is untouched by a footstep.  ");
   set_exits(([
      "southeast":ROOMS"sl1",
      "northwest":ROOMS"sl3",
      ]));
    set_properties(([
       "no teleport":1,
       "snow":1,
       ]));
}

