#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long", "You are travelling along the main path of the petting zoo.  "+
      "Animal exibits line both sides of the path to the north and south.");
    set_exits( ([ "south" : ROOMS + "lambpen",
	"east" : ROOMS + "zoopath14",
	"west" : ROOMS + "zoopath2" ]) );
    set_listen("default", "Faint sounds of lambs calling out can be hear to the south.");
}
