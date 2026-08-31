#include <locations.h>
#include <locations.h>
//      from the Nightmare mudlib
//      an example workroom for new immortals

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The workroom of a new immortal");
    set_night_long("It is night outside.\nA new immortal works here.\n");
    set_day_long("It is day outside.\nA new immortal works here.\n");
    set_exits( ([
      "square" : SQUARE_LOC,
      "hall" : "/d/standard/adv_main",
    ]) );
    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}
