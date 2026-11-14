#include <rooms.h>
#include "path.h"

inherit "/std/room";

int dow() {
	if (!this_player()) return 0;
	write("It would be suicidal to try to climb down here.\n");
	return 1;
}

int cl(string str) {
  if (str=="down") return dow();
  if (!str) {
    write("Where do you want to climb? Down perhaps?\n");
    return 1;
    }
  if (str=="up") {
    write("Not here.\n");
    return 1;
    }
  return 0;
}

create() {
  ::create();
  SetIntShort("cliff");
  SetIntLong(
"You're on the edge of a murky cliff. The walls are many feet above "
"the waterline and the coast. It would be suicide to jump or even climb "
"down. The cliff is much too steep here. The grass on the cliff bends "
"softly in the fresh breeze from the Sea and lots of gulls are circling "
"over your head crying like tiny little babies.\n");
  AddDetail(({"edge","edge of a cliff"}),QueryIntLong());
  AddDetail(({"cliff","murky cliff","steep cliff"}),"It is really steep.\n");
  AddDetail(({"coast","waterline","beach","shore"}),"It is deep below.\n");
  AddDetail(({"grass","green grass","fresh grass","fresh green grass"}),
"The grass is fresh and green.\n");
  AddDetail(({"breeze","fresh breeze"}),
"You hold your face into the breeze and feel it on your cheeks.\n");
  AddDetail(({"sea","ocean","wide sea","wide ocean","blue sea","blue ocean",
  "wide blue sea","wide blue ocean"}),
"It is just the wide blue Sea.\n");
  AddDetail(({"seagulls","seagull","gull","gulls"}),
"The seagulls are extremely noisy.\n");
  AddDetail(({"wave","waves"}),
"Far down you see the waves splashing at the shore.\n");
  SetIntNoise(
"The seagulls are LOUD!!! You hardly can hear the splashing of the waves.\n");
  AddSmell(({"breeze","fresh breeze"}),"You smell salty air.\n");
  SetIndoors(0);
  AddExit("west","./path3");
  AddExit("north","./cliffn");
  AddExit("south","./cliffs");
  AddExit("down",#'dow);
  HideExit("down",1);
  AddExit("climb",#'cl);
  HideExit("climb",1);
  // TODO: //  AddItem(MONSTER("lemm2"),REFRESH_HOME);
}
