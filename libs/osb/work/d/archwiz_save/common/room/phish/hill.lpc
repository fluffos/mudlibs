#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("The bottom of a hill");
  SetIntLong(
"You are standing at the bottom of a hill. It towers "
"majestically above you.  There is a path to the south.\n");
  SetIndoors(0);
  AddDetail(({"hill","majestical hill"}),"It towers majestically above you.\n");
  AddDetail(({"bottom","bottom of a hill"}),QueryIntLong());
  AddDetail(({"path","stony path"}),"It leads south back to Nightfall City.\n");
  AddDetail(({"stone","stones","rocks","rock"}),"The path is stony.\n");
  AddDetail(({"city","nightfall city","nf city"}),"It is to the south.\n");
  AddExit("up","./hilltop");
  AddExit("south",CITY("vill_shore2"));
 }
