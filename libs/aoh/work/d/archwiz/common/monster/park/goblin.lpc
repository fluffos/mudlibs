#include "path.h"
#include <properties.h>
#include <rooms.h>
#include <money.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("goblin");
  SetShort("a goblin");
  SetLong("The head of a goblin pops out of a hole.\n");
  SetLevel(2);
  SetAds(({"head of a","goblin","evil"}));
  SetIds(({"head","goblin"}));
  SetHP(30);
  SetAlign(-30);
  SetAC(0);
  SetWimpy(10);
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney(1,({"gold"}))]));
}
