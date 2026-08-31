#include <std.h>
#include <arlonpath.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A pig pen.");
    set_long(
      "A small pig pen, a fence surrounds the entire area with a gate leading out to the south. A trough sits to the south end of the pen."
    );
    set_night_long(
      "A small pig pen, a fence surrounds the entire area with a gate leading out to the south. A trough sits to the south end of the pen."
    );
    set_exits( 
      (["south" : FARM3"room/farmyard",
      ]) );
    set_property("light", 2);
    set_property("night light", 1);
    set_items(
      (["fence" : "A wall made of wooden slats meant to keep the pig from getting out.",
        "gate" : "A crude made door to this pen.",
        "trough" : "A long crude rectangular feeding box.",
      ]) );
}

void reset() {
    ::reset();
    if(!present("pig"))
        new(MOBS+"pig")->move(this_object());
}
