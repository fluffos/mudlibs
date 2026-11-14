/* original by Smeagol, reimplemented by Rover */

inherit "std/room";

#include <rooms.h>
#include "path.h"

create() {
	::create();
	SetIntShort("Vampire Bat Trees");
	SetIntLong(
"This is the feeding ground of the vampire bats! Everywhere "
"look, there are bones of dead animals.\n");
  AddDetail(({"bones","bone"}),
"They once belonged to some small animal.\n");
  AddDetail(({"trees","tree"}),
"You see many bats hanging in the trees.\n");
  AddDetail(({"animals","animal","dead animals","dead animal"}),
"They do look pretty dead and rotten.\n");
	SetIndoors(0);
	AddExit("west","./pa2n2");
	AddExit("south","./pa1n3");
	AddExit("north","./pa1n1");
	AddItem(MONSTER("park/bat"),REFRESH_HOME,3);
}
