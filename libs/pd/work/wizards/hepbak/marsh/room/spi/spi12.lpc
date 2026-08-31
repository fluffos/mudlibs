#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0]) );
    set_property("cave",1);
    set_property("eyelight", 1);
    set_long(
      "This cave feels like one long tunnel.  It feels hot and stuffy in "
      "here, and there seems to be no end."
    );
    ]));
"west" : SPI "spi13",
}
void reset() {
 ::reset();
    }
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0]) );
    set_property("cave",1);
    set_property("eyelight", 1);
    set_long(
      "This cave feels like one long tunnel.  It feels hot and stuffy in "
      "here, and there seems to be no end."
    );
    set_items(([
        "cave" : "It's one of those air traps from the marsh.",
        "tunnel" : "Two exits, one you come from the one you can go to.",
    ]));
    set_exits( ([
"west" : SPI "spi12",
"east" : SPI "spi14",
    ]) );
}
void reset() {
 ::reset();
      new(MOB"fcloaker")->move(this_object());
  if (!present("worm"))
     new(MOB"worm")->move(this_object());
 
    }
}
#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 0]) );
    set_property("cave",1);
    set_property("eyelight", 1);
    set_short("Gloomy Cave");
    set_long(
      "This cave feels like one long tunnel.  It feels hot and stuffy in "
      "here, and there seems to be no end."
    );
    set_items(([
        "tunnel" : "Two exits, one you come from the one you can go to.",
    ]));
    set_exits( ([
"west" : SPI "spi11",
"east" : SPI "spi13",
    ]) );
}
void reset() {
 ::reset();
   if (!present("shockerlizard")) {
      new(MOB"shockerlizard")->move(this_object());
  if (!present("ooze"))
 
    }
}
