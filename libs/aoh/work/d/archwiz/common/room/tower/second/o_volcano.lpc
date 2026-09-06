#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
  SetDomainDirectory("volcano");
  ::create();
  SetOfficeName("Volcano Isle Domain");
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The 'Volcano Isle' Domain Board",
      P_LONG:"It carries 'd.volcano' (default) and all subgroups.\n",
      "Groups":(({"d.volcano","d.volcano.\\."}))]));
  AddExit("east", "./north2");
  AddExit("north", "/d/volcano/office/room1");
  AddExit("south", "/d/volcano/office/room2");
  AddExit("west", "/d/volcano/office/room3");
}

