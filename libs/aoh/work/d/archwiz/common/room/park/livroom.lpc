#include "path.h"
#include <rooms.h>

inherit "/std/room";

int do_sit(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Sit where?\n"),0;
  write("You sit down for a moment, but then you remember that there "
        "are more important things for you to do! Such as: slaying "
        "monsters, questing and exploring.\n"
        "You stand up again.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("Grandma's livingroom");
  SetIntLong(
"The livingroom looks very comfy. A couch is at the northern wall and a table "
"is in front of it. Two fluffy chairs are next to it, so the whole family can sit "
"there at the weekend. A fluffy carpet covers the floor.\n");
  AddDetail(({"chair","chairs","fluffy chair","fluffy chairs"}),
"They look deep and fluffy, but also as if you should not sit down "
"there right now.\n");
  AddDetail("table",
"It is just a boring table. Nothing special about it.\n");
  AddDetail(({"livingroom","grandma's livingroom","room"}),#'IntLong);
  AddDetail(({"couch","fluffy couch"}),
"It is a fluffy couch with two pillows on it. It looks comfortable.\n");
  AddDetail(({"pillows","pillow"}),"They are grandma's. Leave them alone.\n");
  AddDetail(({"wall","northern wall"}),"A couch is at the northern wall.\n");
  AddDetail(({"carpet","fluffy carpet"}),"It covers the ground.\n");
  SetIndoors(1);
  SetBright(20);
  AddRoomCmd("sit",#'do_sit);
  AddExit("east","./hutentry");
  AddExit("south","./kitchen");
  AddItem(MONSTER("park/grandma"),REFRESH_HOME);
}
