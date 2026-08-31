#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set("short", "The Great Western Highway");
    set("long",
	"The Great Western Highway links the western "
	"lands beyond the mountains to the populated lands of the "
	"valley. What lies beyond the Daroq Mountains is a mystery to the "
        "people of the valley.");
    set_items(
	(["highway" : "A well-traveled dirt road between the "
	    "mountains in the west and the populated towns of the east.",
	  "lands" : "You are in a forested valley with the Daroq "
	    "Mountains in the west.",
	  "mountains" : "The Daroq Mountains, home to many a vicious creature."
    ]));
    set_exits( 
	      (["west" : ROOMS "highway3",
                "east" : ROOMS "highway1"]) );
}

void reset() {
  ::reset();
    if(!present("bag")) 
      new(OBJ"bag")->move(this_object());
}

