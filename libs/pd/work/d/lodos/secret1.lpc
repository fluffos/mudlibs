#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside a small, dark room");
    set_long("%^BOLD%^%^BLACK%^"
      "The exit to the south leads back into the tower. There "
      "is very little light in this room, and the floor is covered in "
      "fresh blood. The entire room looks creepy, from the skulls hanging "
      "from the ceiling as lights to the dark altar before a black mirror.");
    set_items(([ ({ "south", "exit" }) : "It leads back into the tower.",
	"blood" : "Fresh blood has been spilt all over the floor.",
	({"skull", "skulls" }):"Skulls hang from the ceiling as eerie lanterns.",
	"altar" : "The altar has various bones scattered about the top.",
	"bones" : "They look human.."
      ]));
    set_exits(([ "south" : "/d/lodos/tower6" ]));
    set_properties((["light" : 1, "night light" : 0]));
    set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
}

void reset() {
    ::reset();
    if (!present("corpse"))
	make(OBJ"deadguy");
    if (!present("mirror"))
	make(OBJ"mirror");
}
