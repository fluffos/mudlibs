#include "path.h"
#include <properties.h>
#include <moving.h>

inherit "/std/thing";

create() {
  ::create();
  SetShort ("a voting teleporter");
  SetLong (
"This teleporter is the connection to the room where the "
"public discussions/votings take part. "
"Just 'enter' it.\n");
  Set(P_NOGIVE, "You can't do that.\n");
  Set(P_NOGET, "You can't do that.\n");
  Set(P_HELP_MSG,
"Enter it and see what happens.\n"
     );
  AddId ("teleporter");
  AddAdjective ("voting");
}

init() {
  add_action("fenter", "enter");
}

int fenter(string arg) {
  if (!this_player()) return 0;
  if (!arg || !id(arg)) return (int) notify_fail("Enter what?\n"),0;
  return this_player()->move(TOWER("first/voting_room"), M_TELEPORT);
}
