#include "path.h"
#include <rooms.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Conference Of Wicked Step-Mothers");
  SetIntLong(
"You stumbled into the area where the wicked step-mothers "
"gather to create ideas on how to torture their step-daughters "
"and make their husbands' lives miserable.\n");
  SetIndoors(0);
  AddDetail(({"conference","area"}),#'IntLong);
  AddExit("east","./pa4n3");
  AddExit("south","./pa5n4");
  AddExit("north","./pa5n2");
  AddItem(MONSTER("park/stepmother"),REFRESH_HOME,3);
}
