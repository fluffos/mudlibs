///This room needs the up exit hidden until you 'press button', when the panel slides open and the exit becomes available
#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
                "no teleport" : 1]) );
   set_short("Beneath Steel Hammer Monestary");
   set_long(
            "%^BOLD%^%^BLACK%^This dusty room is hidden beneath "
            "Bishop Soulstone's office. A small set of steps lead "
            "up to they way out, which is covered with a wooden "
            "panel. A button is on the wall right beside the "
	    "steps. A small passage leads east.%^RESET%^");
   set_items(([
            "dust" : "A thick layer of dust covers just about everything"
		 " inside the room.",                 
            "steps" : "A small set of steps against the northern "
		 "wall lead back up into Bishop Soulstone's "
	  	 "office.",
	    "button" : "A small, stone button is right next to the "
		 "steps. Given the amount of dust all around, it "
		 "probably doesn't get pushed very often.",
	    "passage" : "A small passage leads east. The walls are "
		 "rough and unfinished.",
	    "panel" : "A wooden panel is used to keep this area "
		 "hidden from Bishop Soulstone's office."
   ]));
   set_smell("default", "A musty odor fills the room.");
   set_listen("default", "It is very quiet.");
   set_exits( ([ 
	"up" : ROOMS "mondoor1",
        "east" : ROOMS "cav1_1"]));
}
