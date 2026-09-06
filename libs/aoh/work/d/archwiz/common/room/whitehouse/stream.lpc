inherit "/std/room";

#include <rooms.h>
#include "path.h"

m_w() {
  return (int) notify_fail(
  "The stream emerges from a spot too small for you to enter.\n") && 0;
}

create() {
  ::create();
  SetIntLong(
"You are standing on a path beside a gently flowing stream. The path "
"follows the stream, which flows from west to east.\n");
  SetIntShort("Stream View");
  SetIntNoise("There is a low noise coming from the stream.\n");
  SetIndoors(1);
  AddDetail(({"path"}),"You are standing on it.\n");
  AddDetail(({"flowing stream","stream","gently flowing stream"}),
"The stream flows from a hole in the west wall into the reservoir to the east.\n");
  AddDetail(({"spot","hole"}),"The streams fills the hole completely.\n");
  AddDetail("reservoir","The reservoir lies to the east.\n");
  AddExit("east","./reservoir_north");
  AddExit("west",#'m_w);
  AddItem(MONSTER("klabauter"), REFRESH_HOME);
}
