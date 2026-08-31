#include <std.h>
#include <arlonpath.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A small corn farm.");
    set_long(
      "A small farmyard. A chicken pen is to the south and a pig pen "
      "is to the north. A grassy field is to the west. A large corn "
      "field is to the east. "
    );
    set_night_long(
      "A small farmyard. A chicken pen is to the south and a pig pen "
      "is to the north. A grassy field is to the west. A large corn "
      "field is to the east. "
    );
    set_exits( 
      (["west" : ARLONPATH"22,5,0",
        "east" : FARM3"0,0,0",
        "north" : FARM3"room/pigpen",
        "south" : FARM3"room/chickenpen",
        "enter house" : FARM3 "room/house",
        "enter barn" : FARM3 "room/barn",
        "enter siloh" : FARM3 "room/siloh",
      ]) );
add_exit_alias("enter house", "house");
add_exit_alias("enter barn", "barn");
add_exit_alias("enter siloh", "siloh");
    set_property("light", 2);
    set_property("night light", 1);
    set_items(
      (["pens" : "A fenced shelter to keep animals in.",
        "pen" : "A fenced shelter to keep animals in.",
      ]) );
}

void reset() {
    ::reset();
    if(!present("house"))
        new(ITEMS "house")->move(this_object());
    if(!present("siloh"))
        new(ITEMS "siloh")->move(this_object());
    if(!present("barn"))
        new(ITEMS "barn")->move(this_object());
    if(!present("farmer"))
        new(MOBS "farmer3")->move(this_object());
}
