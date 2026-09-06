// made by MagicTCS 26 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include <lock.h>
#include "forest.h"

inherit GREENFOREST;

int key;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="down") {
    write(
    "You climb down.\n");
    show(this_player()->QueryName()+" climbs down.\n");
    this_player()->move(DFOREST("forest51"),M_GO,"down");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

int jumpdown(string str) {
  write(
  "You jump down the tree. Ouuch - that hurts! Next time better climb down!\n");
  this_player()->DoDamage(3,DT_BLUDGEON);
  this_player()->move(DFOREST("forest51"),M_GO,"down");
  return 1;
}

int search(string str) {
  object ob;
  if (!str) { notify_fail("Search what?\n"); return 0; }
  if (str=="nest") {
    if (key==0) {
      write(
      "You search the nest and find a black key.\n");
      show(this_player()->QueryName()+
        " searches the nest.\n");
      ob=clone_object("/obj/key");
      ob->SetProperties(([
        P_SHORT:  "a black key",
        P_LONG:   "A black key that will fit into the lock of a black door.\n",
        P_KEYIDS: ({"black key"}),
        P_KEYCODE:"green_forest_black_key",
        P_ADS:     ({"black"}),
        P_WEIGHT:  random(10)+80,
        P_VALUE:   258
      ]));
      ob->move(this_object(),M_SILENT);
      tell_room(TO,"A black key appears in the branches of the nest.\n");
      key++;
      return 1;
    } else {
      write(
      "You searched the nest, but found nothing special.\n");
      show(this_player()->QueryName()+
        " searched the nest, but found nothing.\n");
      return 1;
    }
  }
  if (strstr(str,"nest")!= -1) {
    notify_fail("Try: search nest\n");
    return 0;  
  }
  notify_fail("Search what??\n");
  return 0;
}

int cut(string str) {
  if (!str) { notify_fail("Cut what?\n"); return 0; }
  if (str=="branches" || str=="branch") {
    write(
    "Are you stupid to cut the low branches? You need them to climb down!\n");
    return 1;
  }
  notify_fail("Cut what?\n");
  return 0;
}

create() {
  ::create();
  key=0;
  SetIntShort("In the branches of a lonely tree.");
  SetIntLong(
    "You are in the branches of the lonely tree. There is a small nest\n"
    "inmids the branches.\n");
  AddDetail(({"trees","huge trees"}),
    "You can't see anything here without much leaves and a small nest.\n");
  AddDetail(({"lonely tree","tree","huge tree"}),
    "You are in his branches.\n");
  AddDetail(({"branch","branches","some branches","interesting branch",
    "some interesting branches","interesting branches"}),
    "They consists of brown wood.\n");
  AddDetail(({"nest","small nest"}),
    "It looks like the nest of a magpie. Magpies often hide their stolen\n"
    "items here?\n");
  AddDetail(({"wood","brown wood"}),
    "The branches consist of them.\n");
  AddDetail(({"item","items","stolen item","stolen items"}),
    "Search the nest to find them?\n");
  SetBright(20);
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("search",#'search);
  AddRoomCmd("cut",#'cut);
  AddRoomCmd("down",#'jumpdown);
}

reset() {
  ::reset();
  key=0;
}
