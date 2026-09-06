// the shopkeeper for the voodoo shop
// made by magictcs - 29 may 1997
// nothing special yet
// TODO: add questions about voodoo (magic)

#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Bruzelia");
  SetRace("witch");
  SetShort("Bruzelia");
  SetLong(
    "It's Bruzelia - an old witch who will keep the voodoo shop open.\n"
    "She knows much about old voodoo magic.\n");
  AddId(({"shopkeeper"}));
  SetLevel(30);
  SetGender(GENDER_FEMALE);

  AddQuestion(({"bruzelia","name"}),
    "Bruzelia grummels: Yes, Bruzelia is my real name - why do you ask?\n");

  AddItem(OBJ("vdoll"));
}

