// the gardener of the outer city
// made by magictcs - 10 jul 1997

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Fluffy");
  SetRace("human");
  SetShort("Fluffy, the gardener");
  SetLong(
    "This is Fluffy, the gardener of the outer city. He takes care over\n"
    "the fields of flowers in the garden.\n");
  SetGoChance(10);
  SetLevel(13);
  SetGender(GENDER_MALE);
  AddId(({"gardener"}));
  InitChats(10,({
    "Fluffy hmms.\n",
    "Fluffy works with the flowers.\n",
    "Fluffy looks at some flowers.\n",
    "You hear loud 'schnipp' as Fluffy plucks a flower.\n",
    }) );
}

