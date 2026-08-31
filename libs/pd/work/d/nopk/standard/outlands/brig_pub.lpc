#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The Brigand's Pub");
    set("long",
        "You are in the Brigand's Pub.\n"
        "The pub can get a bit rowdy at times, but you can still manage "
        "to sit down and have a drink, and maybe even grab some grub.");
    set_items(
        (["pub" : "The most hoppin' place in Outland.",
	  "bar" : "The Brigand's Pub.",
	  "foo" : "bar"]) );
set_exits( (["south" : "/d/nopk/forest/tiruneastforest/rooms/tiruneastforest5",
"east"  : "/d/nopk/tirun/fighter/berserker/berserker_join"]) );
    
}

void reset() {
  ::reset();
    if(!present("rocko")) 
new("d/nopk/standard/obj/mon/rocko")->move(this_object());
}

