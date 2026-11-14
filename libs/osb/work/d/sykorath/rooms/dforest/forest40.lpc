// made by MagicTCS 17 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include <moving.h>
#include "forest.h"

inherit GREENFOREST;

int branch;

int climb(string str) {
  object ob;
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    if (branch<5) {
      ob=clone_object("/std/thing");
        if (ob) {
          ob->SetShort("a branch");
          ob->SetLong("A branch, broken from a green tree.\n");
          ob->AddId("branch");
          ob->SetAds(({"small"}));
          ob->SetWeight(1678);
          ob->move(this_object(),M_SILENT);
          write("You try to climb the tree, but only a branch is broken.\n");
          show(this_player()->QueryName()+
            " tries to climb the tree, but fails.\n");
          branch++;
          return 1;
       }
    }
       write("There are no low branches left.\n");
       show(this_player()->QueryName()+
         " tries to climb the tree, but fails.\n");
       return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

int enter (string str) {
  if (!str) return 0;
  if (str=="undergrowth" || str=="forest" || str=="dense undergrowth") {
    write("It is too dense to enter it.\n");
    show(this_player()->QueryName()+
      " tries to enter the undergrowth, but fails.\n");
    return 1;
  }
  return 0;
}

create() {
  ::create();
  branch=0;
  SetIntShort("A green path");
  SetIntLong(
    "A green path in the green forest. There are three different pathes.\n"
    "The other ways are blocked by dense undergrowth.\n");
  AddDetail(({"green path"}),
    "Yes, a green path inmids the green forest.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the west, east, southwest and southeast.\n");
  AddDetail(({"forest","green forest"}),
    "The forest consists of huge trees and dense undergrowth.\n");
  AddDetail(({"tree","huge tree"}),
    "Well - a huge tree, but you can't climb the tree.\n");
  AddDetail(({"trees","huge trees"}),
    "The trees surround the small path.\n");
  AddDetail(({"undergrowth","dense undergrowth"}),
    "You cannot enter it.\n");
  SetBright(20);
  AddExit("southeast",DFOREST("forest14"));
  AddExit("west",DFOREST("forest30"));
  AddExit("east",DFOREST("forest50"));
  AddExit("southeast",DFOREST("forest51"));
  AddExit("southwest",DFOREST("forest31"));
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("enter",#'enter);
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Billy",
       P_SHORT: "billy",
       P_IDS: ({"billy","bear"}),
       P_ADS: ({"liquorice"}),
       P_WEIGHT: 65000,
       P_GENDER: 1,
       P_LONG: 
       "A liquorice bear, the whole body consists of liquorice.\n"
    ]) );
}

reset() {
  ::reset();
  branch=0;
}
