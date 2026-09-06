#include "path.h"
inherit "std/room";

create() {
  ::create();
  SetIntShort("Sunset Boulevard / South Avenue");
  SetIntLong(
"The lanes of Sunset Boulevard split here to circle around a tall "
"fountain placed in the center of this crossing. East and west runs "
"South Avenue. Looking north, you can see the church in the distance.\n");
  AddDetail("fountain",
"The filigran stone arcs, many of them broken, reach up to a height of "
"about ten metres. Once water might have flowed from some larger stone "
"elements in the sculpture but that must have been long ago. The bottom "
"of the fountain is covered with a grey ooze. You quickly retract from "
"the fountain as you see movement in the grey mass.\n");
  AddExit("north",    "./boul2");
  AddExit("south",    "./boul4");
  AddExit("west",     "./southave2");
  AddExit("east",     "./southave3");
  SetIndoors(0);
}
