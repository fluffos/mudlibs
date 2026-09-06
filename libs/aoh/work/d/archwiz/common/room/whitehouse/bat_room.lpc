inherit "/std/room";

#include <rooms.h>
#include "path.h"

int m_e() {
  return (int) notify_fail(
"You try to climb up the slide, but, as you thought, it is too slippery. "
"You will have to find another way out.\n") && 0;
}

m_w() {
  if (present("bat")) return (int) notify_fail(
      "The bats seem to come from that direction.\n") && 0;
  return (int) notify_fail("The shaft has been flodded, sorry.\n") && 0;
}

create() {
  ::create();
  SetIntLong(
"You are in a small room which has doors only to the west and north. "
"To the east ist the end of a steep slide.\n");
  SetIntShort("Bat Room");
  SetIndoors(1);
  AddDetail(({"room","bat room","small room"}),#'IntLong);
  AddDetail(({"doors","door"}),"The doors are out of order.\n");
  AddDetail(({"slide","steep slide","slippery slide"}),
    "It is quite steep and slippery, and you probably can't climb it up.\n");
  AddExit("north","./squeaky_room");
  AddExit("west",#'m_w);
  AddExit("east",#'m_e);
  AddItem(MONSTER("bat"),REFRESH_DESTRUCT,random(3)+1);
}
