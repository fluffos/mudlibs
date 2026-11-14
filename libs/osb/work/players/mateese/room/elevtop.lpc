/* Top of Elevator to my home */

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <moving.h>
#include <rooms.h>

inherit "/std/room";

int fdown (string str);

create() {
  room::create();
  SetIntShort("Top of elevator shaft");
  SetIntLong(
"This is the top end of an elevator shaft.\n"+
"You're standing on pure air. Looking down, you can't see\n"+
"the bottom of the shaft. Bright lights are moving up and\n"+
"down the walls.\n"+
"To the north you see a dimly lit passage.\n"
             );
  AddExit ("north", MR+"mylobby");
  AddExit ("down", #'fdown);
  Set(P_INDOORS, 1);
}

int fdown (string str) {
  object cabin;
  if (str) return 0;
  write ("One of the moving lights gets hold on you and takes you down.\n");
  cabin = clone_object(MR+"elevcabin");
  cabin->move(0);
  PL->move(cabin, M_GO, "down in a globe of light");
  return 1;
}

