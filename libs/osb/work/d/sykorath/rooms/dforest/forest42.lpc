// made by MagicTCS 23 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include "forest.h"

inherit GREENFOREST;

int water;

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
  if (str=="river" || str=="little river") {
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
    this_player()->move(DFOREST("forest62"),M_GO,
           "to the east, stepping over the river");
    return 1;
  }
  notify_fail("Step over what?\n");
  return 0;
}

int goeast() {
  write(
  "This way leads directly into the water. Brrrrb - you don't want to enter\n"
  "the river.\n");
  return 1;
}

int drink (string str) {
  string norm;
  int drink;
  notify_fail("You can drink water from the river.\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (str=="water from river" || str=="water from little river" ||
      str=="water from the river" ) {
    if (water>0) {
      drink=TP->QueryDrink();
      if (TP->QueryMaxDrink()<=drink) {
        write("You can't drink anymore!\n");
        say(NAME+" tries to drink water from the river, but fails.\n");
        return 1;
      }
      drink+=10;
      water-=10;
      if (drink>=TP->QueryMaxDrink()) drink=TP->QueryMaxDrink();
      TP->SetDrink(drink);
      write("You drink some water from the river.\n");
      say(NAME+" drinks some water from river.\n");
      return 1;
    }
    else {
      write("The water looks not as good as before. Try it later!\n");
      say(NAME+" tries to drink water from river, but fails.\n");
      return 1;
    }
  }
  return 0;
}

// maybe hide a gold nugget in the river?

create() {
  ::create();
  water=100;
  SetIntShort("A path");
  SetIntLong(
    "A small place inmids the green forest.\n"
    "A little river can be seen to the east.\n");
  AddDetail(({"place","small place"}),#'QueryIntLong);
  AddDetail(({"path","another path"}),
    "Where may this path leads to?\n");
  AddDetail(({"pathes","different pathes"}),
    "There is only one path southeast.\n");
  AddDetail(({"forest","green forest"}),
    "A green forest - green like most of the forests in this world.\n");
  AddDetail(({"tree"}),
    "Well - one of the huge trees, but you can't climb it.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the place.\n");
  AddDetail(({"river","little river"}),
    "A little river with wet water.\n"
    "May you can find the way leading east?\n");
  AddDetail(({"water","wet water","blue water"}),
    "It is blue water, yes and it is wet too. You don't really want to\n"
    "enter it, because you will get wet feet.\n"
    "But the water on this side of the river seems drinkable.\n");
  AddDetail(({"east","other side","side"}),
    "There is another path on the other side of the river.\n");
  AddDetail("way","Yes, there is a way to other side. Can you find it?\n");
  SetBright(20);
  AddExit("southwest",DFOREST("forest33"));
  AddExit("east",#'goeast);
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("step",#'step);
  AddRoomCmd("drink",#'drink);
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Blubber",
       P_SHORT: "blubber",
       P_IDS: ({"blubber","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 62070,
       P_GENDER: 1,
       P_AGGRESSIVE: 0,
       P_LONG: 
       "A bear which consists of liquorice.\n"
    ]) );
}

reset() {
  ::reset();
  water=100;
}
