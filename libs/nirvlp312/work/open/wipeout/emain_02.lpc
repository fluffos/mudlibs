#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "east main & 2nd";
  long_desc =
"    "+HIB+"East main and Second"+NORM+". \n\
  The center of town has more compact business in old red brick four\n\
story buildings. These building have been made historic facilities so\n\
they can never be bought and destroyed. This seems to be a small down\n\
town from the 1940's or 50's. The Handy Andy gas station is on the\n\
corner to the south and the new CVS pharmacy is towards the northeast.\n";
  items =
  ({
    "Handy Andy",
    "A small convenient store that is a part of a small chain",
    "pharmacy",
    "A place to purchase medicine",
     
});
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_03",   "east",
    "/players/angel/area/town/room/main_01",    "west",
    "/players/angel/area/town/room/cvs",        "cvs",
    "/players/angel/area/town/room/handyandy",  "station",
  });
}