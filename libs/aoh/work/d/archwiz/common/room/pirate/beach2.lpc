#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include "path.h"

inherit "/std/room";

swim() {
  write("You would not survive this!\n");
  return 1;
}

int dig(string str) {
  if (!str) return (int) notify_fail(
  "Dig where?\n") && 0;
  if ((lower_case(str)!="sand") && (lower_case(str)!="in sand")
    && (lower_case(str)!="at sand")) return (int) notify_fail(
"You should be more specific.\n") && 0;
  write("You dig for a time...and you find nothing!\n");
  return 1;
}

int enter(string str) {
  if (!str) return (int) notify_fail(
"What do you want to enter?\n") && 0;
  if (lower_case(str)!="cave") return (int) notify_fail(
"Are you sure you could enter this here?\n") && 0;
  if (!this_player()) return 0;
  this_player()->move(PIRATE("incave"),M_GO,"west");
  return 1;
}

int up() {
  if (!this_player()) return 0;
  this_player()->move(PIRATE("drope"),M_GO,"up");
  write("You climb up again.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("a small beach");
  SetIntLong(
"This is a small beach. To the north and south the cliff raises high "
"into the sky. You see some letters on it. Some fins of sharks can be "
"seen in the ocean. An ominous and dark cave entrance lies to the west.\n");
  AddDetail(({"letter","letters"}),
"You see large letters carved into the cliff. Perhaps you should "
"try to read them.\n");
  AddReadMsg(({"letters","letter"}),
"You read:\n"
"On many levels, several are ancient, but the sixth is forever.\n");
  AddDetail(({"small beach","beach"}),QueryIntLong());
  AddDetail(({"cliff","high cliff","steep cliff"}),
"The cliff raises high into the air. You remark some letters that are "
"carved into it.\n");
  AddDetail(({"fin","fins","shark","sharks"}),
"Some sharks seems to be in the ocean here.\n");
  AddDetail(({"sea","wide sea","blue sea","wide ocean","blue ocean",
  "wide blue sea","wide blue ocean"}),
"It is the wide blue Sea.\n");
  AddDetail(({"pirates hideout","hideout","evil priates hideout",
  "evil hideout","cave","entrance","cave entrance"}),
"This looks like a real pirates hideout. You get an evil feeling "
"when you look at it.\n");
  AddDetail(({"fine sand","sand"}),
"You see nothing special, just fine sand.\n");
  SetIndoors(0);
  AddExit("up",#'up);
  HideExit("up",1);
  AddExit("climb",#'up);
  HideExit("climb",1);
  AddExit("swim",#'swim);
  HideExit("swim",1);
  AddExit("enter",#'enter);
  HideExit("enter",1);
  AddRoomCmd("dig",#'dig);
}
