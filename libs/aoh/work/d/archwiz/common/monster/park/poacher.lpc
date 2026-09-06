#include "path.h"
#include <properties.h>
#include <combat.h>
#include <rooms.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetRace("human");
  SetName("poacher");
  SetShort("a poacher");
  SetLong("A tall man with an evil grin.\n");
  SetLevel(5);
  SetGender(1);
  SetHP(50);
  SetAlign(-60);
  SetAC(4);
  SetWimpy(10);
  AddQuestion("hunter",
"The poacher screams.\n"
"He looks around nervously.\n"
"He says: Don't tell him what we are doing! He'll kill us!!!!\n");
  AddQuestion(({"grandma","witch","witches","riding hood","hood","girl",
    "little red riding hood","red riding hood"}),
"The poacher says: Shut up! I don't care about anyone here around!\n");
  AddQuestion(({"animals","animal","squirrel","squirrels","rabbit","rabbit",
    "wolf","deer","fox"}),
"The poacher smiles.\n"
"The poacher whispers: Those animals have very valuable fur, you know?\n");
  AddItem("/std/armour",REFRESH_REMOVE,#'wearme,
    ([P_SHORT: "a baseball cap",
      P_LONG: "A red with black square cap.\n",
      P_IDS: ({"cap","helmet"}),
      P_ADS: ({"red","black square","baseball"}),
      P_WEIGHT: 500,
      P_ARMOUR_TYPE:AT_HELMET,
      P_AC: 1,
      P_VALUE: 160,
      P_RESET_QUALITY:40+random(60),
      P_SIZE:PSIZE_NORMAL]));
}
