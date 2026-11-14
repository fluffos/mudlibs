#include "path.h"
#include <moving.h>

inherit "/std/room";

int bowl;

stairs() {
  object ob;
  if (!this_player()) return 0;
  if (bowl) return "You find an empty cache beneath the stairway.\n";
  show(this_player()->QueryName()+
    " finds a cache beneath the stairway and a bowl\n"
    "in it.",this_player());
  see("You discover a bowl in a small cache you find beneath the stairs.\n");
  bowl=1;
  ob=clone_object("/std/thing");
  ob->SetShort("a jeweled bowl");
  ob->SetLong("A large, expensive looking jeweled bowl.\n");
  ob->SetValue(200);
  ob->SetWeight(1000);
  ob->SetIds(({"bowl"}));
  ob->SetAds(({"jeweled","large","expensive looking","a","an"}));
  if (ob->move(this_player(),M_GET)!=ME_OK) {
    write("You cannot carry the bowl, so you drop it.\n");
    ob->move(this_object(),M_DROP);
    }
  return "";
}

create() {
  ::create();
  SetIntShort("a cave");
  SetIntLong(
"You're in a cave with walls which seem to absorb the light. A large stone "
"stairway leads up.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"large stairs","stone stairs","large stairway","stairs",
              "stairway","stone stairway"}),#'stairs);
  AddDetail("cave",QueryIntLong());
  AddDetail(({"walls","wall"}),"The walls seem to absorb the light.\n");
  AddDetail(({"floor","ground","ceiling"}),"It doesn't look special.\n");
  AddDetail(({"stone","normal stone"}),"Normal stone.\n");
  AddExit("northwest","./incave3");
  AddExit("up","./incave5");
}

reset() {
  ::reset();
  bowl=0;
}
