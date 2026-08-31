#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "Sun Alley");
    set("long",
	"Sun Alley goes no further east now, only west. West along Sun Alley, "
	"Honin Road connects to this small alley. Near the northern side of the "
	"road is a staircase leading down into the earth. Right near the stairs "
	"is a sign posted in the ground. A building of some sort is east. You "
	"could enter the building to the east from here.");
    set_exits(([
      "west"   : ROOMS"sun1",
      "down"   : ROOMS"spy",
      "enter"  : ROOMS"bar"
    ]));
    set_items(([
	"sign" : "\n  _                        _\n ( )--.,,.----------.,,.--( )	\n  |                        |\n"
		 "  |           -            |\n  |        Spyder's        |\n  |          Web           |\n"
		 "  |           -            |\n  |                        |\n (_)--.,,.----------.,,.--(_)",
        "building" : "The building has a sign on it. The sign depicts a rusting "
		     "blade and written in paint is: The Dull and Rusty Tavern.",
	"staircase" : "It leads straight into the ground."
    ]));
}

