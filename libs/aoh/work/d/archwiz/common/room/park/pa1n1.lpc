/* original by Smeagol, reimplemented by Rover */

inherit "std/room";

#include <rooms.h>
#include "path.h"

create(){
	::create();
	SetIntShort("Rattlesnake Den");
	SetIntLong(
"There are a bunch of holes in the ground. Listening closely "
"you can hear something rattling. There are some beady eyes "
"looking out of the holes!\n");
	AddDetail(({"hole","holes"}),"There are just ordinary holes.\n");
  AddDetail(({"eyes","eye"}),
"The eyes are staring at you.\n");
	SetIndoors(0);
	SetIntNoise("You can hear some rattling noises.\n");
	AddExit("west","./pa2n1");
	AddExit("south","./pa1n2");
	AddItem(MONSTER("park/rattlesnake"),REFRESH_HOME,3);
}
