inherit "/std/room";
#include <rooms.h>
#include <moving.h>
#include "path.h"

int try_n() {
  if (!this_player()) return 0;
  if (this_player()->QueryDex() < 15) 
    write("There is nothing to hold on in the slit.\n");
  this_player()->move(SLITROOM,M_GO,"into the slit");
  return 1;
}

int jump_n_die() {
  write("Hmmm... this was not such a good idea...\n"
"In the movies, your life would be passing before your eyes.\n"
"\n   *** You have died ***\n\n");
  return this_player()->move(CITY("church"),M_GO,"into heaven");
}

QueryIntLong() {
  string str;
  int rdelta;
  str = "You are at the west edge of a deep canyon. Passages lead off "
"to the south, northwest and southwest. To the north, the canyon narrows "
"to a vertical slit in the cave wall.\n";
  rdelta = DAMROOM->reservoir_delta();
  if (rdelta == 0)
    str += "You can hear the sound of flowing water from below.\n";
  else if (rdelta < 0)
    str += "There is a loud sound of rushing water coming from below.\n";
  return str;
}

create() {
  ::create();
  SetIntShort("Deep Canyon");
  SetIndoors(1);
  SetIntNoise("You hear water from below.\n");
  AddDetail(({"canyon","deep canyon"}),
    "It is quite deep and you'd better be careful not falling into it.\n");
  AddDetail(({"slit","vertical slit","narrow slit","narrow, vertical slit"}),
    "A narrow, vertical slit. There is hardly anything you could use to hold on.\n");
  AddDetail(({"edge","west edge"}),
    "You are at the edge of a deep canyon.\n");
  AddDetail(({"passages","passage"}),
    "Passages lead off to different directions.\n");
  AddDetail(({"walls","wall","cave wall","cave walls","northern wall",
	      "north wall"}),
    "A slit is in the northern wall.\n");
  AddDetail(({"water","rushing water","flowing water"}),
    "It must be deep below.\n");
  AddExit("northwest","./n_s_passage");
  AddExit("southwest","./reservoir_north");
  AddExit("south","./dam");
  AddExit("north",#'try_n);
  AddRoomCmd("jump",#'jump_n_die);
}
