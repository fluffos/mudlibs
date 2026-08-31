#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long",	"You are travelling along the main path of the petting zoo.  "+
      "Animal exhibits line both sides of the path to the east and west.");
    set_exits( ([ "east" : ROOMS + "coral",
	"north" : ROOMS + "zoopath11",
	"south" : ROOMS + "zoopath13" ]) );
    set_listen("default", "Sounds of horses neighing can be heard from the east.");
}
