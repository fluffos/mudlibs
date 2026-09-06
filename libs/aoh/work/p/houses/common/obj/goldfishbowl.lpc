// add a new feature for the OEFC catalogue
// a fish bowl with a golden piranha in it
// made by MagicTCS  12/8/96

#include <rooms.h>
#include <properties.h>

inherit "/std/thing";

varargs void create() {
  (::create());
  AddId("fishbowl");
  SetShort("a goldfishbowl");
  SetLong(({"This is golden fishbowl. A golden piranha swims in the bowl ",
   "You see a golden piranha swimming in the fishbowl. "
    "Maybe you can get him?\n"}));
  SetIds(({"bowl","goldfishbowl"}));
  SetAds(({"golden"}));
  SetNoGet("The fishbowl is clued to the ground \n");
  SetWeight(2000);
  SetValue(5000);
}

void init() {
  ::init();
  add_action("get","get");
//  if (present("fishbowl",environment())
//    remove();
}

int get(string str) {
  if (str!="piranha") return 0;
  write ("Huuu - the piranha bites you into the finger.\nSome  blood is "
    "dropping on the floor.\n");
  return 1;
}
