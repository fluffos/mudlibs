/*
 * a stone dragon for the place of the bruned down house of the patrician
 *
 * created by Magictcs - 22 jan 98
 *
 * updates:
 *
 */

// TODO: add more features..., details..., description

#include <properties.h>
#include <sykorath.h>

inherit "/std/thing";

create() {
  ::create();
  SetShort("a stone dragon");
  SetLong(
    "This looks like a giant dragon. But you aren't scared of it. It is "
    "made of stone. A mighty mage has casted a spell here to transform a "
    "real dragon into this one. The eyes of the dragon are two diamonds. "
    "You aren't sure if they have moved just in this moment.\n"
    "Some words are burned into the stone.\n");

  AddSubDetail(({"word","words","some words"}),
    "The words are burned directly into the stone. Must be mighty magic, "
    "that can do that.\n");
  AddSubReadMsg(({"word","words","some words"}),
    "You read the words burned into the stone dragon:\n"
    "  -> Never try to build a house here! <-\n"
    "You wonder who don't want this?!\n");

  AddSubDetail(({"diamonds","two diamonds","diamond","eyes","eye"}),
    "Yes the eyes of this dragon seems to be real diamonds. But you "
    "aren't able to break them out of the stone. They are securily "
    "fixed by mighty magic.\n");

  SetNoGet("You can't carry that giant stone dragon.\n");

  AddId(({"dragon","__patrician_dragon__"}));
  AddAdjective("stone");
}

