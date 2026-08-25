inherit "/std/room";
#include "path.h"

void setup() {
set_short("Dendall:  Masoleum");
set_light(70);
   add_property("no_undead",1);
set_long("\n   Dendall:  Masoleum.\n\n"
        "     As you step into this building, you feel yourself break into "
        "a cold sweat, while all the hairs on the back of your neck stand "
        "straight out. Row "
	"upon row of tombs and crypts. Although there is no smell of "
	"rot or decay, the smell of death itself hangs heavy in the air. "
	"The crypts are very well tended, and the area is close to "
	"immaculate. You wonder who would take such a job, when "
	"you notice a shadow flicker to your side...it appears that "
	"shadow servants do the upkeep around here.  It makes sense "
	"because no living being could stand something like this for "
	"long.  Looking more closely about the room, you now notice "
	"the runes of warding and sealing used on the tombs, as well "
	"as the carvings and friezes here. Maybe it's the atmosphere, "
	"but the carvings and glyphs seem infinitely more sinister "
	"in this place. Finally, far to the back of the room, you notice "
	"one tomb that seems more ornate and well-crafted than the "
	"others. Perhaps a former thane or important official now "
	"resides there.\n\n"); 

add_item(({"tomb","tombs","crypt","crypts","row","rows"}),
        "This is where those who could not affoard a resurrection "
        "ended up.  Sealed, like canned worms for eternity.\n");
add_item("servants","These shadow servants keep this Masoleum in "
        "proper Grimbrand fashion, Dark and Dreary, and very clean.\n");
add_item(({"runes","glyphs","carvings"}), "The writings, symbols, "
        "and carvings around each tomb and crypt are there to "
        "seal them shut so that nothing can enter, or exit...\n");
add_item("friezes","These are much like the other carvings, but "
        "bear no magical properties.  They are mainly decoration, "
        "placed here to please Grimbrand and those who follow him.\n");

  add_exit("north", HERE+"den01", "door");
}
