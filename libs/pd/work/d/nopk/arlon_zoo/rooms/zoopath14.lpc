#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long",	"You've reached a turn along the main path of the petting zoo.  "+
      "Animal exhibits line both sides of the path to the east and south.");
    set_exits( ([ "east" : ROOMS + "llamapen",
	"north" : ROOMS + "zoopath13",
	"west" : ROOMS + "zoopath15" ]) );
    set_smell("default", "There is a slight breeze carrying a faint odor from the east.");
}
