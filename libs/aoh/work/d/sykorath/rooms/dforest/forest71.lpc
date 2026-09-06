// made by MagicTCS 26 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <lock.h>
#include <moving.h>
#include "forest.h"

inherit GREENFOREST;

//***********
// climb tree
//***********
int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write(
    "You try to climb the tree, but you see no way to the first branch.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

//***********
// enter door
//***********
int enterdoor() {
  write(
    "You enter the door. Something wonderful is happened! You are back\n"
    "in Sykorath!\n");
  TP->move(SYKORATH("mainplaza"),M_GO,"into the door");
  return 1;
}

//************
// enter hedge
//************
int enter (string str) {
  if (!str) return 0;
  if (str=="hedge") {
    write("You cannot enter the hedge, but maybe you can pass it?\n");
    show(this_player()->QueryName()+
      " tries to enter a dense hedge, but fails.\n");
    return 1;
  }
  return 0;
}

//***********
// pass hedge
//***********
int pass (string str) {
  if (!str) return 0;
  if (str=="hedge") {
    write(
    "You discover a small slit in the hedge. You enter the small slit.\n");
    this_player()->move(DFOREST("forest61"),M_GO,"into the hedge");
    return 1;
  }
  return 0;
}

//*************************
// block a simple 'go west'
//*************************
int gowest() {
  write("The way is blocked by a dense hedge.\n");
  return 1;
}

create() {
  ::create();
  SetIntShort("A clearing in the forest");
  SetIntLong(
    "A clearing in the green forest. Trees are standing around you.\n"
    "A dense hedge can be seen to the west.\n"
    "You noticed something that will irritate you.\n");
  AddDetail("clearing",#'QueryIntLong);
  AddDetail("path","Only one path leads to the west.\n");
  AddDetail("way","There is a way leading west into the hedge.\n");
  AddDetail(({"pathes","different pathes"}),
    "There is only one path here.\n");
  AddDetail(({"forest","green forest"}),
    "Some huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees look unclimbable.\n");
  AddDetail(({"branch","branches"}),"The trees have branches too.\n");
  AddDetail("lowest branch","You can't reach the lowest branch.\n");
  AddDetail(({"hedge","dense hedge"}),
    "The dense hedge blocks the way to the west.\n");
  AddDetail("something",
    "A black door inmids the forest? You can't believe what you see.\n");
  SetBright(20);
  AddExit("west",#'gowest);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("pass",#'pass);
  AddRoomCmd("climb",#'climb);
  AddDoor("east",#'enterdoor,"black door",
    "A door in a forest? Must be an illussion?\n",
    ({"green_forest_black_key","black key"}),
    LOCK_LOCKED);
}

