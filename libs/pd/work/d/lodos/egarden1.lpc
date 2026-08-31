#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "light" : 2, "forest" : 1,
                    "night light" : 1 ]));
   set_short("Eastern entrance to a garden");
   set_day_long("This is the eastern entrance to a garden surrounding "
     "the northern tower. A small meadow grows just north of a little "
     "creek. Around the creek grow many long cattails that wave in "
     "the breeze. Long weeds grow near the bank of the creek. Stepping "
     "stones lead north, further into the garden.");
   set_night_long("The dim moonlight shines on the garden, sending "
     "shadows onto the tower to the west. Trees grow near the tower, "
     "but east is a small creek, bubbling and babbling. Dark cattails "
     "sway in the cool night breeze.");
   set_items(([
     "cattails" : "They grow around weeds and wildflowers.",
     "garden"   : "The garden goes further north.",
     "flowers"  : "Wildflowers grow all over the place.",
     "wildflowers":"A wide array of colors.",
     "weeds"    : "They have been left around the cattails and flowers."
   ]));
   set_exits(([ "north" : ROOMS"egarden2",
                "west" : ROOMS"ntown8"
   ]));
}

void reset() {
 ::reset();
   if (!present("weed"))
     make(MOB"weed");
}
