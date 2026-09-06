// the shopkeeper for the general shop
// made by magictcs - 22 may 1997
// nothing special yet

#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Mafiosi");
  SetRace("italian");
  SetShort("Mafiosi");
  SetLong(
    "It's Mafiosi - the shopkeeper of the general shop. He will protect\n"
    "the shop against any robbers from outer space. He is very experienced\n"
    "in this job, because he did it sometimes in the past.\n"
    "He likes to wear dark sunglasses.\n");
  AddId(({"shopkeeper"}));
  SetLevel(40);
  SetGender(GENDER_MALE);

  AddQuestion(({"mafiosi","name"}),
    "Mafiosi grummels: Yes that's my real name - why do you ask?\n");

  AddItem("/obj/sunglasses",REFRESH_REMOVE);
}

