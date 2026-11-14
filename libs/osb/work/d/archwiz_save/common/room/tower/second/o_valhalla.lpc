#include "path.h"
#include <properties.h>
#include <rooms.h>

inherit STD("d_office");

void create() {
  SetDomainDirectory("valhalla");
  ::create();
  SetOfficeName("Valhalla Domain");
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The Valhalla Domain Board",
      P_LONG:"It carries 'd.valhalla' (default) and all subgroups.\n",
      "Groups":(({"d.valhalla","d.valhalla.\\."}))]));
  AddExit("south","./north2");
}
