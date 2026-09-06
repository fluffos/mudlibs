// a short example made for Hanarra
// made by Magictcs - 3 apr 98
// You can make it nicer by using the P_AMOUNT prop of the
// vitems-> show the coin only while searching and looking
// if it is there! (and not taken away)

#include <properties.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

// special func for the long of the bridge:
string look_bridge() {
  if (TP) TP->Set("Has_looked_at_bridge",1);
  return "It's a huge drawbridge. You see a crack there.\n";
}

// another for the crack
string look_crack() {
  if (TP) {
    if (TP->Query("Has_looked_at_bridge")) {
      TP->Set("Has_looked_at_crack",1);
      return "A small crack is there. Maybe you can search it?\n";
    }
  }
  return 0;         // cannot look at it!
}

// and one for the coin:
string look_coin() {
  if (TP) {
    if (TP->Query("Has_searched_crack")) {
      TP->Set("Has_looked_at_coin",1);
      return "There is a coin inside the crack.\n";
    }
  }
  return 0;
}

// clone the coin, only if the player had looked at it!
object clone_coin() {
  object c;
  if (TP) {
    if (TP->Query("Has_looked_at_coin")) {
      c=clone_object("/std/thing");
      c->SetProperties( ([
        P_IDS: ({"coin"}),
        P_SHORT: "a coin",
        P_LONG: "Well a coin, what else?\n"
      ]) );
      return c;
    }
  }
  return 0;
}

// search functions:
OnSucceedSearchingCrack() {
  if (TP) TP->Set("Has_searched_crack",1);
  write("You search the crack and find a coin there.\n");
  return 1;
}
create() {
  string vitem_bridge,vitem_coin,vitem_crack;
  ::create();
  SetIntShort("A testroom");
  SetIntLong(
    "Try to look at the drawbridge, the crack there and try to "
    "search the crack, try to get the coins and and and...\n");

  // now the vitems:
  vitem_bridge=AddVItem( ([
    P_IDS:  ({"drawbridge","bridge"}),
    P_LONG: #'look_bridge
  ]) );

  vitem_crack=AddVItem( ([
    P_IDS:  ({"crack"}),
    P_ADS:  ({"small"}),
    P_LONG: #'look_crack
  ]) );

  vitem_coin=AddVItem( ([
    P_IDS:  ({"coin"}),
    P_LONG: #'look_coin,
    PV_ITEM_LOCATION: #'clone_coin
  ]) );
  AddSkill(SK_SEARCH,"crack",20,vitem_crack);
}
