#include <lib.h>
#include <domains.h>
#include "../minaret.h"

inherit "/domains/yozrath/virtual/desert";

inherit LIB_ROOM;

static void create(int x, int y) {
  ::create(33, 47);
  SetShort("in the barren Yozrath Desert");
  SetClimate("arid");
  SetLong("The Yozrath Desert is a massive expanse of sand "
    "and barren waste that seems to go off into the horizon "
    "without end. Far off in the distance to the east, the faint "
    "outlines of the Estergrym mountains stand against the sky, "
    "while far off to the west the FrostMarches taint the horizon. "
    "To the southwest lie the Crystal Reaches.  East of here lies "
    "the beginning of the path along the minaret."
          );
  SetItems( ([
      ({ "minaret", "path", }) : "The towering minaret and its path start "
          "just east of here.",
     ]) );
  SetItemAdjectives( ([
     "minaret" : "towering",
    ]) );
  RemoveExit("east");
  AddExit("east", MIN_ROOMS "/path0t1");
  SetRoom(33,47);
  SetSmell( ([
    "default" : "The desert air is remarkably clean and crisp.",
    ]) );
  SetListen( ([
    "default" : "Sand shifts and occasionally a deep rumble comes from the desert sands.",
    ]) );
}
