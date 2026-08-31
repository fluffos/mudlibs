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
    set_short("Morvudd's Closet");
    set_night_long("It is night outside.\nMorvudd codes here, shoo!\n");
    set_day_long("It is day outside.\nMorvudd codes here, shoo!\n");
    set_exits( ([
	"square" : SQUARE_LOC,
	"hall" : "/d/standard/adv_main",
      ]) );
    set_smell("default", "It smells like stale buttcrack and cornchips in here.");
    set_listen("default", "All around you, you hear the sound of souls being oppressed.");
}
