#include "path.h"
#include <rooms.h>

inherit "/std/room";

int do_search(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Search what or where?\n"),0;
  if ((str!="bushes") && (str!="bush") && (str!="low bushes")
    && (str!="low bush")) return notify_fail(
"You eagerly search "+lower_case(str)+", but you find nothing.\n"),0;
  write("You search the bushes, but find nothing unusual.\n");
  show(capitalize(this_player()->QueryName())+" searches the bushes.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("Wild Pig's Area");
  SetIntLong(
"What is that sound?  You see a bush with eyes glowing. "
"You seem to be in the middle of some Wild Pig's Area.\n");
  SetIndoors(0);
  AddDetail("puddle",
"It is dirty and slimy like pigs love it.\n");
  AddDetail(({"slime","dirt","mud"}),
"It fills the whole puddle.\n");
  AddDetail(({"bush","bushes"}),
"There are eyes glowing in the bush. As you look closer you see it's "
"a pig.\n");
  AddDetail(({"eyes","eye"}),
"They do belong to some wild pigs.\n");
  AddRoomCmd("search",#'do_search);
  AddExit("west","./pa4n2");
  AddExit("east","./pa2n2");
  AddExit("south","./pa3n3");
  AddExit("north","./pa3n1");
  AddItem(MONSTER("park/pig"),REFRESH_HOME,2);
}
