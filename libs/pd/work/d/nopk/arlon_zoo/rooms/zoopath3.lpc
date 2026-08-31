#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long", "You are travelling along the main path of the petting zoo.  "+
      "Animal exhibits line both sides of the path to the north and south.");
    set_exits( ([ "west" : ROOMS + "zoopath4", 
	"east" : ROOMS + "zoopath2",
	"south" : ROOMS + "goatpen" ]) );
    set_listen("default", "Faint sounds of goats bleating can be hear to the south.");
}
