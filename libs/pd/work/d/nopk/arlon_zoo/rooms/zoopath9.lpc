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
    set_exits( ([ "north" : ROOMS + "mousehouse",
	"west" : ROOMS + "zoopath8",
	"east" : ROOMS + "zoopath10" ]) );
    set_listen("default", "Faint sounds of mice squeaking can be heard from the north.");
}
