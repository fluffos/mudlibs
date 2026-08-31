#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set_property("no castle", 1);
    set("short", "A path leading through the orc fortress");
    set("long",
          "The dirt path is often traveled by the orcs and their "
          "current allies. The dirt has been packed down by constant "
          "travel. The trees and foliage are very thick here.");
    set_exits( 
	      (["north" : ROOMS"south_orcs/open",
          "south" : ROOMS"south_orcs/path2"]) );
}
