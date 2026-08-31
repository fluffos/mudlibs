#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long",	"You are on the main path through the petting zoo.  "+
      "Animal exhibits line both sides of the path to the east and west.");
    set_exits( ([ "south" : ROOMS + "zoopath5",
	"west" : ROOMS + "dogkennel",
	"north" : ROOMS + "zoopath7" ]) );
    set_listen("default", "Sounds of dogs yipping come from the west.");
}
