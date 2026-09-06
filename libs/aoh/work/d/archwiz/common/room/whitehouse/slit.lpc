inherit "/std/room";

#include <rooms.h>
#include <moving.h>
#include "path.h"

jump_n_die() {
  write("Hmmm... this was not such a good idea...\n"
"In the movies, your life would be passing before your eyes.\n"
"\n   *** You have died ***\n\n");
  return this_player()->move(CITY("church"),M_GO,"towards heaven");
}

QueryIntLong() {
  string str;
  int rdelta;
  str="You barely manage to hold onto the slippery wall, even though you are "
"such a dextrous person. You may only climb backwards or forwards, northwest "
"or south. The canyon seems to make a slight turn here.\n";
  rdelta = DAMROOM->reservoir_delta();
  if (rdelta == 0)
    str += "You can hear the sound of flowing water from deep below.\n";
  else if (rdelta < 0)
    str += "There is a loud sound of rushing water coming from deep below.\n";
  return str;
}

QueryIntNoise() {
  int rdelta;
  rdelta=DAMROOM->reservoir_delta();
  return
    rdelta?"There is a loud sound of rushing water coming from deep below.\n":
      "You can hear the sound of flowing water from deep below.\n";
}

create() {
  ::create();
  SetIntShort("Narrow Canyon");
  SetIndoors(1);
  AddDetail(({"walls","wall","slippery walls","slippery wall"}),
"The walls are slippery.\n");
  AddDetail(({"canyon","narrow canyon"}),
"The canyon has very slippery walls. But as there is no real ground "
"one hast to hold onto the walls.\n");
  AddDetail(({"ground","floor"}),
"There is no real ground. The walls meet each other instead.\n");
  SetExplorable(({"canyon","narrow canyon"}));
  AddExit("northwest","./loud_room");
  AddExit("south","./canyon");
  AddRoomCmd("jump",#'jump_n_die);
}
