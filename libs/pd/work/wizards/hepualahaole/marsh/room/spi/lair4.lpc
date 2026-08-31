#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0]) );
    set_property("eyelight", 1);
    set_short("Gloomy Cave");
    set_long(
ocean::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("Dragon Lair");
    set_long(
      " In the swampy-waters, swimming."
          );
    set_items(([
        "water" : "Mixture of blue and brown.",
    ]));
    set_listen("default", "Burbles of air bubbles escaping upwards.");
    set_exits( ([
"north" : SPI "lair8",
"east" : SPI "lair5",
"south" : SPI "lair",
"west" : SPI "lair3",
    ]) );
}
