// made by MagicTCS 19 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include "forest.h"
#include <money.h>

inherit GREENFOREST;
inherit MONEY_LIB;

int moss;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write(
    "You try to climb the tree, but there is no way up.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

int go_se() {
  write("You are pierced by the thornes.\n");
  this_player()->DoDamage(3,DT_PIERCE);
  this_player()->move(DFOREST("forest32"),M_GO);
  return 1;
}

int enter(string str) {
  if (!str) { notify_fail("Enter what?\n"); return 0; }
  if (str=="bush" || str=="bushes") {
    return go_se();
  }
  notify_fail("Enter what?\n"); 
  return 0;
}

int search(string str) {
  object ob;
  if (!str) { notify_fail("Search what?\n"); return 0; }
  if (member(({"moss","green moss","wet moss","green wet moss",
    "wet green moss"}),str)!=-1) {
    write("You search the green and wet moss, ");
    show(this_player()->QueryName()+" searches the green moss, ");
    if (moss<3) {
      write("and find some money.\n");
      say("and found some money.\n");
      ob=clone_object(MONEY);
      ob->SetProperties(([P_MONEY :(["gold":random(7)+2]) ]));
      ob->move(this_object(),M_TELEPORT,"blinks under the moss");
      moss++;
    }
    else {
      write("but you find nothing.\n");
      say("but found nothing.\n");
    }
    return 1;  
  }
  notify_fail("Search what?\n");
  return 0;
}

create() {
  ::create();
  moss=0;
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest. There is a bush to the southeast.\n"
    "The ground is covered by green moss.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the northeast and southeast.\n");
  AddDetail(({"forest","green forest"}),
    "This forest contains trees over trees.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "The trees are green except the trunk.\n");
  AddDetail("trunk","Yes the trunk is brown.\n");
  AddDetail(({"bush","dense bush"}),
    "You can pass the bush by going southeast, but the bush has some sharp\n"
    "thornes, that will pierce you.\n");
  AddDetail(({"bushes","dense bushes","some bushes",
    "some dense bushes"}),
    "There is only one bush to the southeast.\n");
  AddDetail(({"thornes","sharp thornes","thorn","sharp thorn"}),
    "They will pierce you!\n");
  AddDetail("ground",
    "It is covered by wet green moss.\n");
  AddDetail(({"moss","green moss","wet moss","green wet moss",
    "wet green moss"}),
    "The moss is green and wet and you can search the moss.\n");
  SetBright(20);
  AddExit("southeast",#'go_se);
  AddExit("northeast",DFOREST("forest30"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Bumbi",
       P_SHORT: "bumbi",
       P_IDS: ({"bumbi","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 67810,
       P_GENDER: 2,
       P_AGGRESSIVE: 1,
       P_LONG: "A huge bear, looking at you..\n"
    ]) );
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("pass",#'enter);
  AddRoomCmd("search",#'search);
}

reset() {
  ::reset();
  moss=0;
}
