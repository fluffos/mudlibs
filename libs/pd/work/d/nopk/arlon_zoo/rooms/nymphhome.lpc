#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "An empty house");
    set("long", "This looks to be an empty house.  There is a "+
      "large sign on the wall next to a matressless bed.\n");
    set_items( (["sign": "Due to parental concerns, The nymph exhibit has been closed.  "+
	"We appologize for any inconvenience this may cause and thank you for your "+
	"continued patronage.\n\nDarien the zookeeper\n" ]) );
set_exits( ([ "west" : ROOMS + "zoopath11" ]) );
}
