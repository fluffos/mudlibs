/* A room in the house of ende */

#include <rooms.h>
inherit "/d/avalon/common/std/room";

create() {
  ::create();
  SetIntShort("Garden, the dart game");
  SetIntLong("The dart board here, which is nailed to the wall of the house, invites you to\ntry your luck.\n");
  AddExit("south","/d/archwiz/common/houses/ende/101");
  AddItem("/d/avalon/common/obj/dartboard",REFRESH_NONE);
}
