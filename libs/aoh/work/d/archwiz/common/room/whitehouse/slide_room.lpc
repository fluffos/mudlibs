inherit "/std/room";

#include <moving.h>
#include "path.h"

int m_s() {
  return (int) notify_fail(
    "You can't be serious! A granite wall.\n") && 0;
}

int m_d() {
  if (!this_player()) return 0;
  write("You slide down the chute. Wheee what a fun!\n");
  return this_player()->move(WHITEHOUSE("bat_room"),M_GO,"down");
}

create() {
  ::create();
  SetIntLong(
"This is a small chamber, which appears to have been part of a coal "
"mine. On the south wall of the chamber the letters ``Granite Wall'' are "
"etched in the rock. To the east is a long passage, and there is a steep "
"metal slide twisting downward.\n");
  SetIntShort("Slide Room");
  SetIndoors(1);
  AddDetail(({"slide room","room","chamber","small chamber"}),
    #'IntLong);
  AddDetail(({"coal mine","mine"}),"This chamber could be part of it.\n");
  AddDetail(({"letters","letter"}),
    "If you read them, you might get to know what they mean.\n");
  AddDetail(({"rock","natural rock"}),"Natural rock.\n");
  AddDetail(({"long passage","passage"}),"It leads eastwards.\n");
  AddDetail(({"wall","south wall","walls","southern wall"}),
    "I guess you mean the south wall. Well, it feels like granite!\n");
  AddDetail(({"steep slide","slide","metal slide","steep metal slide"}),
    "It is very steep. You probably wouldn't be able to climb back up.\n");
  AddReadMsg(({"letters","letter"}),"You read: ``Granite Wall''\n");
  AddExit("east","./cold_passage");
  AddExit("north","./mine_entrance");
  AddExit("south",#'m_s);
  AddExit("down",#'m_d);
}
