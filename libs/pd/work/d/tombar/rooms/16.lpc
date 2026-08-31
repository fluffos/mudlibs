// Coded by Whit

#include <std.h>
#include <tombar.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a long, black hallway");
    set_long("This part of the temple seems darker and hallways seem longer "
      "the deeper inside you go.  The walls are made from a black stone which "
      "is wet with water from the dripping sceiling.  The floor is covered in "
      "an inch thick puddle of water.");
    set_smell("default", "A musty smell is here.");
    set_exits(([
	"northwest" : ROOMS"15",
	"south" : ROOMS"17",
      ]));

    set_items(([
	"floor" : "There is a large puddle of water on it.",
	"ceiling" : "Water is dripping from it.",
	(({"wall", "walls"})) : "The walls are made from black stone.",
      ]));

}
