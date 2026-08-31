#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
    ::create();
    set_short("The highest, northeastern most point of the temple.");
    set_day_long("This is the highest northeastern most point of the entire "
      "temple, turrets included. Stones have been lined up to make a ledge "
      "around the outside edges of the turret. The whole countryside "
      "northeast of the temple can be seen from here.");
    set_night_long("The entire northeastern countryside from the temple can "
      "be seen in the moonlight from here. This is the highest northeastern "
      "point of the entire temple and turret. Stones and rocks have been "
      "arranged along the outside edge of the turret to make a ledge that "
      "could be used to sit on, or for defense.");
    set_items(([
	"ledge" : "As close to a wall as is out here.",
	"stones": "Many stones have made a ledge along the outside wall of "
	"this turret.",
	"country":"The northeastern country can be seen."
      ]));
    set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
    set_exits(([
	"down"  : ROOMS"l1ne2",
	"west"  : ROOMS"l2ne1",
	"south" : ROOMS"l2ne4",
      ]));
}

void reset() {
    ::reset();
    if (!present("magician"))
	make(MOB"2t2");
}

