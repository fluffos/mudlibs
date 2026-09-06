// the librarian for the library
// made by magictcs - 16 jun 1997

#include <properties.h>
#include <npc.h>
#include <sykorath.h>

inherit "/std/npc";

create() {
  if (::create()) return;
  SetName("Purzel");
  SetRace("dwarf");
  SetShort("Purzel, the librarian");
  SetLong(
    "Purzel is an old dwarf. She is working in the library.\n");
  SetGoChance(0);
  SetLevel(13);
  SetGender(GENDER_FEMALE);
  AddId("librarian");

  /* questions */
  AddQuestion(({"scrolls"}),
    "Purzel says: You can look at them or you can take the scroll you want,\n"
    "  but please let the scrolls here for other players.\n");
}

