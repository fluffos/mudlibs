#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
  SetDomainDirectory("halfling");
  SetOfficeName("Halfling Domain");
  ::create();
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The Halfling Domain Board",
      P_LONG:"It carries 'd.halfling' (default) and all subgroups.\n",
      "Groups":(({"d.halfling","d.halfling.\\."}))]));
  AddExit("south","./west1");
  AddExit("north",  "/d/halfling/common/hobbiton/church");
  AddDoor("west", "/players/suamor/haus/111","very little door","The door leads to Suamor's workroom",0,1);
}
