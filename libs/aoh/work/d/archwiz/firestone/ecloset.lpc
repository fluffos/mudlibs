#include "path.h"
#include <moving.h>

inherit "/std/room";

int east()
{
  if (!this_player())
    return 0;
  tell_room(this_object(),"The door opens.\n");
  this_player()->move(FIRESTONE("r_t10"),M_GO,"east");
  tell_room(this_object(),"The door closes.\n");
  tell_room(FIRESTONE("r_t10"),"The door closes.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("In a closet");
  SetIntLong("You are in a closet on the Enterprise 1701.\n");
  SetIndoors(1);
  AddExit("east",#'east);
}
