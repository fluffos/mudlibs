#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long", "You've reached a turn along the main path of the petting zoo.  "+
      "Animal exhibits line both sides of the path to the north and east.");
    set_exits( ([ "east" : ROOMS + "nymphhome",
	"west" : ROOMS + "zoopath10",
	"south" : ROOMS + "zoopath12" ]) );
}
