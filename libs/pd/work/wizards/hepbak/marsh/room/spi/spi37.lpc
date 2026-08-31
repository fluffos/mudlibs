#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Gloomy Cave");
    set_long(
      "This cave feels like one long tunnel.  It feels hot and stuffy in "
      "here, and there seems to be no end. PUT A HIDDEN EXIT DOWN"
    );
    set_items(([
        "cave" : "It's one of those air traps from the marsh.",
        "tunnel" : "Two exits, one you come from the one you can go to.",
      
    ]));
    set_exits( ([
"north" : SPI "spi45",
"down" : SPI "lair5",
    ]) );
}
