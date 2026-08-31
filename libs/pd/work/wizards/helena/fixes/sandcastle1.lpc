#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 3, "night light" : 2, "indoors" : 1,]) );
    set_short("Grand Hall");
    set_long("You are standing in the Grand Hall of the sandcastle. The ceiling above seems to have been made from the skeleton of a fish. There's a room to the west, east, north, and a staircase in front of you. The sunlight somehow makes its way inside, making it very bright. The drawbridge closes to the south, closing off the entrance.");
set_night_long("You are standing in the Grand Hall of the sandcastle. The ceiling above seems to have been made from the skeleton of a fish. There's a room to the west, east, north, and a staircase in front of you. Although it is night time, the light inside still seems to be bright. The drawbridge closes to the south, closing off the entrance.");
    set_items((["room" : "It is the Grand Hall of the sandcastle. Somehow it seems very well kept and very well made. Perhaps it has something to do with the fish skeleton..", "ceiling" : "The backbone and ceiling of the entire castle seems to be made from a fish skeleton...Flounder, if you're not mistaken.", "walls" : "The walls are well made, compacted together, with no signs its going to fall apart any time soon.", "floor" : "There's a lot of sand at your feet. Not a surprise considering you're in a sandcastle..."]));
    set_smell("default", "Smells an awful lot like dead fish and seaweed...and the ocean.");
    set_listen("default", "The sound of the ocean is distant in the background, while the silence that surrounds you is deafening.");
    set_exits( (["west" : ROOMS"sandcastle2", "stairs" : ROOMS"sandcastle7", "north" : ROOMS"sandcastle6", "east" : ROOMS"sandcastle3"]) );
}

void reset() {
  ::reset();
    if(!present("chest", this_object()))
      new(ITEMS "chest1")->move(this_object());
    if(!present("shell", present("chest",this_object())))
      new(ITEMS "seashell")->move(present("chest", this_object()));
}

