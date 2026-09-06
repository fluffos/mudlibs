// made by MagicTCS 19 mar 97
// part of the eatcorpse quest

#include <properties.h>
#include "forest.h"

inherit GREENFOREST;

int puddle;

int climb(string str) {
  if (!str) { notify_fail("Climb what?\n"); return 0; }
  if (str=="tree" || str=="huge tree") {
    write("You try to climb the tree, but there are no low branches left.\n");
    show(this_player()->QueryName()+" tries to climb the tree, but fails.\n");
    return 1;
  }
  notify_fail("Climb what?\n"); 
  return 0;
}

string lookpuddle() {
  switch (puddle) {
    case 0:
    case 1: return "The puddle is filled with clear water.\n";
    case 2:
    case 3: return "There is some clear water in the puddle.\n";
    case 4:
    case 5: return "Only a rest of clear water is left.\n";
    default: return "There is no water left.\n";
  }
}

string lookwater() {
  if (puddle<=5) return "The water is clear and drinkable.\n";
  return "Which water?\n";
}

int drink(string str) {
  string norm;
  int drink;
  notify_fail("You can drink water from puddle.\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (str=="water from puddle" || str=="water from small puddle") {
    if (puddle<=5) {
      drink=TP->QueryDrink();
      if (TP->QueryMaxDrink()<=drink) {
        write("You can't drink anymore!\n");
        show(NAME+" tries to drink water from puddle, but fails.\n");
        return 1;
      }
      drink+=10;
      puddle++;
      if (drink>=TP->QueryMaxDrink()) drink=TP->QueryMaxDrink();
      TP->SetDrink(drink);
      write("You drink some water from the puddle.\n");
      show(NAME+" drinks some water from puddle.\n");
      return 1;
    }
    else {
      write("There is no water to drink. Try it later!\n");
      show(NAME+" tries to drink something, but fails.\n");
      return 1;
    }
  }
  return 0;
}

create() {
  ::create();
  puddle=0;
  SetIntShort("A path in the forest");
  SetIntLong(
    "A path in the green forest. A small puddle is there.\n");
  AddDetail("path",#'QueryIntLong);
  AddDetail(({"pathes","different pathes"}),
    "You can go to the northeast and south.\n");
  AddDetail(({"forest","green forest"}),
    "Many unnumbered huge trees are standing around.\n");
  AddDetail(({"tree","trees","huge tree","huge trees"}),
    "Huge, green, nothing special.\n");
  AddDetail(({"puddle","small puddle"}),#'lookpuddle);
  AddDetail(({"water","clear water"}),#'lookwater);
  SetBright(20);
  AddExit("northeast",DFOREST("forest32"));
  AddExit("south",DFOREST("forest24"));
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Blinzel",
       P_SHORT: "blinzel",
       P_IDS: ({"blinzel","bear"}),
       P_ADS: ({"liquorice","fierce"}),
       P_WEIGHT: 79810,
       P_GENDER: 2,
       P_ALIGN: -60,
       P_AGGRESSIVE: 1,
       P_LONG: "A fierce looking liquorice bear.\n"
    ]) );
  AddItem(EATCORPSE("lbear"),REFRESH_DESTRUCT,
    ([ P_NAME: "Blip",
       P_SHORT: "blip",
       P_IDS: ({"blip","bear"}),
       P_ADS: ({"liquorice","little"}),
       P_WEIGHT: 55060,
       P_GENDER: 1,
       P_AGGRESSIVE: 1,
       P_LONG: "A little liquorice bear!\n",
    ]) );
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("drink",#'drink);
}

reset() {
  ::reset();
  puddle=0;
}
