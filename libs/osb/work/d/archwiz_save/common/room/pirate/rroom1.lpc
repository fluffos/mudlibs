#include "path.h"
#include <moving.h>

inherit "/std/room";

int speak(string str) {
  if (str!="lie with passion and be forever damned") return (int)
    notify_fail("Wrong!\n") && 0;
  write("CORRECT !\n");
  say("CORRECT !\n");
  write("You're teleported away ...\n");
  if (!this_player()) return 0;
  show(this_player()->QueryName()+" is teleported away.\n",this_player());
  this_player()->move(PIRATE("allexit"),M_SILENT);
  return 1;
}

create() {
  ::create();
  SetIntShort("chamber");
  SetIntLong(
"You're in another chamber. Another face is on the wall and another sign.\n");
  SetIndoors(1);
  SetBright(0);
  AddReadMsg(({"sign"}),
"'Speak' the 7 in sequence, separated by spaces! "
"And you'll be able to continue your quest!\n");
  AddDetail("face","It looks pretty normal.\n");
  AddDetail("sign","There is something written on it.\n");
  AddRoomCmd("speak",#'speak);
  AddExit("up","./out");
}
