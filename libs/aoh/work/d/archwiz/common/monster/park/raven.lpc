#include "path.h"
#include <money.h>
#include <rooms.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("raven");
  SetShort("a black raven");
  SetLong("This is a black raven, starring at you.\n");
  SetIds(({"bird","raven"}));
  SetLevel(1);
  SetHP(15);
  SetAC(1);
  SetHands(({({"beak",0,4}),({"claws",0,2})}));
  SetAlign(-20);
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney(1,({"silver"}))]));
}
