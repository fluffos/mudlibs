#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Western wall of a temple");
   set_day_long("Daylight flows into this western length of the magnificent "
     "temple through tall stained glass windows. The temple's stained glass "
     "windows are a beautiful sight to behold during the day. Sunlight "
     "shines through the windows and a stunning array of reds, greens, "
     "blues, yellows and many other colors illuminate this room. A few "
     "candles float magically against the eastern wall.");
   set_night_long("This room is the western length of the temple. Though "
     "the same show of colors from the stained glass windows cannot be "
     "seen at night, candles illuminate the room fairly well. The onyx walls "
     "would make an excellent background for the 'light show' the stained "
     "glass windows would put on during the daylight.");
   set_items(([
     "candles" : "The candles float along the eastern wall of this room, "
                 "by some magic force.",
     "windows" : "What a magnificent sight to behold! Every hue and array "
                 "of color imaginable!",
     "wall"    : "The white onyx wall would give the stained glass windows "
                 "an excellent background to splash their color upon."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "north" : ROOMS"l1m1",
     "south" : ROOMS"l1m7"
   ]));
}


