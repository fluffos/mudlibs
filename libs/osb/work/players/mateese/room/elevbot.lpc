/* Bottom of Elevator to my home */

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <moving.h>
#include <rooms.h>

inherit "/std/room";

int fup (string str);

create() {
  room::create();
  SetIntShort("Bottom of elevator shaft");
  SetIntLong(
"This is the bottom end of an elevator shaft.\n"+
"Looking up, you can't see the top of the shaft.\n"+
"Bright lights are moving up and down the walls.\n"+
"There is a dark tunnel leading south.\n"
             );
  AddExit ("south", MR+"elevcave");
  AddExit ("up", #'fup);
  SetIntLight(1);
  Set(P_INDOORS, 1);
}

int fup (string str) {
  object cabin;
  if (str) return 0;
  write ("One of the moving lights gets hold on you and takes you up.\n");
  cabin = clone_object(MR+"elevcabin");
  cabin->move(1);
  PL->move(cabin, M_GO, "up in a globe of light");
  return 1;
}

