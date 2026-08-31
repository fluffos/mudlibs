#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Along the path");
    set("long",	"You've reached a turn along the main path of the petting zoo.  "+
      "Animal exhibits line both sides of the path to the west and south.");
    set_exits( ([ "west" : ROOMS + "pigpen", 
	"east" : ROOMS + "zoopath3",
	"north" : ROOMS + "zoopath5" ]) );
    //    set_door("gate", ROOMS"pigpen", "west");
    set_listen("default", "Sounds of pigs grunting can be heard to the west.");
}
