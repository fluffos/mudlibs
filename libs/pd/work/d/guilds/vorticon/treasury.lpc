//Treasury
//treasury.c

#include <std.h>
#include <guild.h>
inherit TREASURY;

void create() {
    ::create();
    set_guild("vorticon");
    set_property("light", 3);
    set_property("night light", 2);
    set_property("no magic", 1);
    set_property("no attack", 1);
    set_property("no castle", 1);
    set_property("no steal", 1);
    set_property("no teleport", 1);
    set_property("no scry", 1);
    set_short("The Vorticon Treasury");
    set_long("%^BOLD%^WHITE%^The room is reasonably cluttered, "
      "it is where the Vorticon guild come to store their numerous"
      " amounts of %^RESET%^ORANGE%^treasure%^BOLD%^WHITE%^. The "
      "stone floor declines in the centre where a large pit "
      "dominates the rest of the room.  Countless amounts of "
      "%^BOLD%^YELLOW%^gold coins%^WHITE%^ and %^RESET%^CYAN%^g"
      "%^BOLD%^BLUE%^e%^MAGENTA%^m%^RESET%^GREEN%^s%^BOLD%^WHITE%^"
      " are deposited in it. Four %^BLACK%^gar%^BLUE%^go%^BLACK%^"
      "yle%^WHITE%^ statues stand in each corner of the room "
      "each with their eyes focused on the pit.");
    set_listen("default", "Whispering can be heard all around the room.");
    set_exits(([ "east": VORTICON "hall"]));
    set_items(([ "floor": "A featureless stone floor.",
	"pit": "The pit is nothing more than a decline in the floor"
	" but all the treasures the guild owns are deposited into it.",
	({"gargoyle statues", "statues", "statue"}): "Each "
	"statue features a gargoyle with its %^RED%^blood"
	" red eyes%^RESET%^ focused on the pit as if they "
	"were guarding it. Below each is a small sign "
	"which is legible %^BOLD%^BLUE%^<read sign>"
	"%^RESET%^"
      ]));
}

