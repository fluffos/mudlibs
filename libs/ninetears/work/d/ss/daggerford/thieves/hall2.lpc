/* source file -- Gallery of Rogues*/
#include "path.h"

inherit "/std/room";
 
void setup()
{
  set_short("Gallery of Rogues");
  set_long("Into the underground depths stretches a magnificent "+
    "gallery.  Raw oaken timbers span the ceiling high "+
    "overhead.  The air is musty yet dry and is reminiscent of "+
    "ash.  Two sturdy iron-bound doors flank each side of this "+
    "intersection.  To each side of the doors, a small lit torch "+
    "sits within a sconce. On the walls to each side is a "+
    "remarkably old tapestry.\n");
  set_light(70);
  set_zone("guild");

  add_item( ({"timbers", "beams", "rafters"}),
    "The rafters are as solid as a the rock above them and as "+
    "big as a stone giant's arm.\n");
  add_item( "doors",
    "Each door is layered with iron plate with a small "+
    "sliding embrasure so that other people can see into "+
    "the hallway.\n");
  add_item( ({"torch", "torches" }),
    "They look just like ordinary torches.  You don't "+
    "need them.\n");
  add_item( ({"tapestry", "tapestries"}),
    "One of the tapestries depicts a black-clad figure "+
    "lurking in the shadows of a noble's residence.  "+
    "He holds his mortally-coated tool poised for "+
    "the approaching target.\n\nThe other tapestry shows "+
    "a dextrous individual crossing a network of "+
    "tightropes, platforms, traps, and other obstacles "+
    "while lingering over fires, pits, and abysses.  "+
    "At the other end lies the magical power that "+
    "he and his battle-weary friends have within "+
    "their grasp.\n");

  add_exit("west", ROOM + "kitchen",  "door");
  add_exit("east", ROOM + "storage", "door");
  add_exit("north", ROOM + "hall1", "door");
  add_exit("south", ROOM + "hall3", "door");
}

