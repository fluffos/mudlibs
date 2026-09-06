// made by MagicTCS 23 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include "forest.h"

inherit GREENFOREST;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write("You try to climb the tree, but the branches are too high.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

int enter (string str) {
  if (!str) return 0;
  if (str=="river" || str=="little river" || str=="water" || str=="wet water") {
    write(
    "You don't want to get wet feet. But it seems that you can step over\n"
    "the little river.\n");
    show(this_player()->QueryName()+
      " tries to enter the river, but fails.\n");
    return 1;
  }
  return 0;
}

int step (string str) {
  if (!str) { notify_fail("Step over what?\n"); return 0; }
  if (str=="over river" || str=="over little river") {
    write("You step over the little river.\n");
    this_player()->move(DFOREST("forest42"),M_GO,
           "to the west, stepping over the river");
    return 1;
  }
  notify_fail("Step over what?\n");
  return 0;
}

int gowest() {
  write(
  "This way leads directly into the water. Brrrrb - you don't want to enter\n"
  "the river.\n");
  return 1;
}

// maybe hide a gold nugget in the river?

create() {
  ::create();
  SetIntShort("A path");
  SetIntLong(
    "Another path in the green forest.\n"
    "To the west is a little river.\n");
  AddDetail(({"path","another path"}),
    "Where may this path leads to?\n");
  AddDetail(({"pathes","different pathes"}),
    "You can go to the north and southwest.\n");
  AddDetail(({"forest","green forest"}),
    "Yes it is a forest. No woodcutter can be seen.\n");
  AddDetail("woodcutter","No woodcutters are here!\n");
  AddDetail(({"tree"}),
    "Well - one of the huge trees, but you can't climb it.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the path.\n");
  AddDetail(({"river","little river"}),
    "A little river with wet water.\n"
    "May you can find the way leading west?\n");
  AddDetail(({"water","wet water","blue water"}),
    "It is blue water, yes and it is wet too. You don't really want to\n"
    "enter it, because you will get wet feet.\n");
  AddDetail(({"west","other side","side"}),
    "There is another path on the other side of the river.\n");
  AddDetail("way","Yes, there is a way to other side. Can you find it?\n");
  SetBright(20);
  AddExit("southwest",DFOREST("forest44"));
  AddExit("north",DFOREST("forest61"));
  AddExit("west",#'gowest);
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("step",#'step);
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Blob",
       P_SHORT: "blob",
       P_IDS: ({"blob","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 65000,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: 
       "A friendly liquorice bear.\n"
    ]) );
}
