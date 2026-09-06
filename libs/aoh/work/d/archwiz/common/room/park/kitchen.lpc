#include "path.h"

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Grandma's kitchen");
  SetIntLong(
"This room obviously is the kitchen. You see pots and cans everywhere. An old "
"hearth stands in the southwestern corner, but nothing is being cooked right "
"now.\n");
  AddDetail(({"hearth","old hearth"}),"It's not used in the moment.\n");
  AddDetail(({"room","grandma's kitchen","kitchen"}),#'IntLong);
  AddDetail(({"pots","cans","can","pot"}),
"These items all belong to grandma. Not even YOU would steal from her.\n");
  SetIndoors(1);
  SetBright(20);
  AddExit("north","./livroom");
}
