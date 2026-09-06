#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("Wooden Bridge");
  SetIntLong(
"The road crosses a west-east running stream on a wooden bridge here. "
"On both sides of the stream are fields full with crops.\n");
  AddExit("north", "./crop");
  AddExit("south", "./fields");
  SetIndoors(0);
}
