#include <std.h>
#include <rain.h>

inherit ROOM;
create() {
   ::create();
   set_short("First house on the block");
   set_long("You are standing at the first house of a big block. "
            "There are a few trees outside the home and also some "
            "bushes.");
   set_exits((["west" : ROOMS"home3",
               "south" : ROOMS"home4",
               "east" : ROOMS"home2",
               "enter" : ROOMS"house1",
               "north" : ROOMS"hpath2"]));
   set_items((["trees" : "There are 3 tall trees outside of this house.",
               "bushes" : "There are a few bushes outside the house"]));
}
