// the shopkeeper of the candy shop
// made by magictcs - 2 jul 1997

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Sweety");
  SetRace("human");
  SetShort("Sweety, the sweet girlie");
  SetLong(
    "Sweety is a very beautiful girlie. She is the shopkeeper of the candy\n"
    "shop. She likes candy very much!\n");
  AddQuestion(({"candy","sugar",}),
    "Sweety says: Oh yes - I love it very much!\n");
  SetGoChance(0);
  SetLevel(13);
  SetGender(GENDER_FEMALE);
  AddId(({"girlie"}));
  AddAdjective(({"beautiful","very beautiful","sweet"}));
}

