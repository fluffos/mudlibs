#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "indoors" : 1]));
    set_short("Main Hall");
    set_smell("default", "The smells here are clean, old, and intriguing at the same time.");
    set_listen("default", "Hardly any sound is heard, it is very peaceful.");
    set_long("The main hall of the Palace is huge, with a high ceiling, wonderfully carved wall patterns and pictures, and a soft yet strong floor. The enchanting hallway leads further on to the east, or there are different halls leading north and south. The way out is to the west.");
    set_items((["walls" : "Intricate patterns and pictures are carved here, beautiful to look at, mesmerizing to the eye.", "floor" : "It is made out of stone, yet kind to the feet, and warm to the touch.", "ceiling" : "High above everyone is the palace ceiling, also with carvings and patterns upon it. Those are too far away to be seen clearly."]));
    set_exits( (["west" : ROOMS"pentrance", "east" : ROOMS"p2", "north" : ROOMS"princess1", "south" : ROOMS"prince1"]) );
}

void reset() {
  ::reset();
    if(!present("guard")) {
      new(MOB"guard")->move(this_object()); }
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object());
  }
}
