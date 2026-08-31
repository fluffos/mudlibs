#include <std.h>
#include <arlon.h>

inherit ROOM;

void create() {
    ::create();
    set_property("town", 1);
    set_property("light", 2);
    set_property("night light", 1);
    set_short("Along the road of urban renewal");
    set_long("Along the road of urban renewal.\n Many houses can be seen "
          "scattered east from here. They are all seperated by "
          "streets running everywhere.");
 
 set_exits ( ([ "west" : ROOMS "hgates3",
                "east" : ROOMS "hgates5", ]) );
 
}
