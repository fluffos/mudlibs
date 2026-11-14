// made by MagicTCS 20 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include "forest.h"
#include <money.h>

inherit GREENFOREST;

int stone;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree" || str=="up") {
    write(
    "You try to climb the tree, but the trunk is too wet to climb up.\n");
    show(NAME+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

int get(string str) {
  object ob;
  if (!str) { notify_fail("Get what?\n"); return 0; }
  if (present(str)) return 0;        // for dropped items
  if (member(({"stone","small stone","small stone from ground",
    "stone from ground"}),str)!=-1) {
    if (stone<3) {
      ob=clone_object("/std/unit");
      if (ob) {
        ob->SetShort("small stone");
        ob->SetLong("A small stone, nothing special with it.\n");
        ob->SetPluralLong("Some small stones, nothing special with it.\n");
        ob->Set(P_WEIGHT_PER_UNIT,35);
        ob->SetAmount(1);
        ob->AddId("stone");
        ob->AddPluralId("stones");
        ob->SetAds(({"small"}));
        if (ob->move(TP,M_GET)) {
      write("You take a small stone from the ground.\n");
      show(NAME+" gets a small stone from the ground.\n");
      stone++;
        }
      }
    }
    else {
      if (present(str)) return 0;
      write(
      "Please let some stones left here - else the ground will no longer\n"
      "makes the noise if you walk over them.\n");
      say(NAME+" searches the ground.\n");
    }
    return 1;  
  }
  notify_fail("Get what?\n");
  return 0;
}

string lookstone() {
  if (stone<3) return
    "You can take a small stone!\n";
  return "There is no intersting stone here.\n";
}

string lookstones() {
  if (stone<3) return
    "Yes, much small stones are here. They make some noise if you walk\n"
    "over them. But take a closer look at a small stone.\n";
  return
    "Yes, much small stones are here. They make some noise if you walk\n"
    "over them.\n";
}

create() {
  ::create();
  stone=0;
  SetIntShort("A path in the forest");
  SetIntLong(
    "A small path with some trees around.\n"
    "The ground makes some noise.\n");

  AddDetail(({"path","small path"}),#'QueryIntLong);
  AddDetail(({"pathes","small pathes"}),
    "You can go to the east and southwest.\n");
  AddDetail(({"forest","green forest"}),
    "Trees are all around you.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees are green wth a brown trunk.\n");
  AddDetail("trunk","The trunk is brown and too wet to climb up.\n");

  AddDetail(({"ground"}),
    "There are much small stones.\n");
  AddDetail(({"stones","small stones","much stones","much small stones"}),
    #'lookstones);
  AddDetail(({"stone","small stone"}),#'lookstone);

  SetIntNoise(
    "The ground makes some noise, as you step over the small stones.\n");
  SetBright(20);
  AddExit("southwest",DFOREST("forest21"));
  AddExit("east",DFOREST("forest40"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Babs",
       P_SHORT: "babs",
       P_IDS: ({"babs","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 67810,
       P_GENDER: 2,
       P_AGGRESSIVE: 1,
       P_LONG: "A funny liquorice bear..\n"
    ]) );
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("get",#'get);
  AddRoomCmd("take",#'get);
}

reset() {
  ::reset();
  stone=0;
}
