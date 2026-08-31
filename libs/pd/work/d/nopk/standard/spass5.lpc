#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Southern wall along the Daroq Mountains Pass");
    set("long",
        "This small, thin path along the southern ledge above the "
        "Daroq Mountain pass is not exactly the safest place to be. "
        "Parts of the path have fallen off, leaving very unstable "
        "spots along this ledge, from rock falls.");
    set_exits(([ "west" : ROOMS"spass6",
                 "east" : ROOMS"spass4" ]));
}
