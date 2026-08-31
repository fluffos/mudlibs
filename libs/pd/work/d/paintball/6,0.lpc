#define PAINT "/d/paintball/"
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("(6,0)");
   set_long("%^BOLD%^%^GREEN%^You are at coordinates: (6,0)\n"
       "%^BLACK%^You are on top of a giant "
       "grid or matrix of some sort. The lines that make up the grid "
       "are green and the ground they are on is black. The grid continues "
       "almost as far as you can see in every direction.");
   set_items(([ "grid" : "It is the paintball warfare arena." ]));
   set_exits(([
      "north": PAINT"6,1",      // x    ,   up
      "east" : PAINT"7,0",       // up   ,   x
      "west" : PAINT"5,0"      // down ,   x
   ]));
}
