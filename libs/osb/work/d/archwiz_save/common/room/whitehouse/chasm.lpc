inherit "/std/room";

#include <moving.h>
#include "path.h"

int jump_n_die() {
  write("Hmmm... this was not such a good idea...\n"
"In the movies, your life would be passing before your eyes.\n"
"\n   *** You have died ***\n\n");
  this_player()->move(CITY("church"),M_GO,"to heaven");
  return 1;
}

create() {
  ::create();
  SetIntLong(
"A chasm runs northwest to southeast and the path follows it. "
"You are on the north side of the chasm, where a crack opens into a "
"north passage.\n");
  SetIntShort("Chasm");
  SetIndoors(1);
  AddDetail(({"chasm","north side","side"}),#'IntLong);
  AddDetail(({"crack"}),"It opens to the north.\n");
  AddDetail(({"north passage","passage"}),"It leads north.\n");
  AddDetail(({"path",}),"It follows the chasm.\n");
  AddExit("north","./n_s_passage");
  AddExit("southeast","./reservoir_north");
  AddExit("northwest","./e_w_passage");
  AddRoomCmd("jump",#'jump_n_die);
}
