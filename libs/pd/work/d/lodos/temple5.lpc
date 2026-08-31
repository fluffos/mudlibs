#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside a temple to Omicron");
    set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
    set_property("light", 3);
    set_long("The ladder leads up and down, up into the hall of "
      "peace and down into the temple to Omicron. The dark "
      "blue tiles have begun to get a greenish tint to them.");
    set_exits(([ "down" : ROOMS"temple4",
	"up" : ROOMS"temple6" ]));
}

void reset() {
    ::reset();
    if (!present("cleric"))
	new(MOB"cleric")->move(this_object());
}
