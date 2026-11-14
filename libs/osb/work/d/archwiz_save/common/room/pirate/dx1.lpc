#include "path.h"
#include <rooms.h>
#include <money.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("a small chamber");
  SetIntLong("You're in a small cavern. There is some blood at one of the walls.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"walls","wall","blood"}),"Something is written on the wall.\n");
  AddDetail(({"chamber","room","small room","cavern","small chamber",
  "small cavern","cave","small cave"}),
QueryIntLong());
  AddDetail(({"ground","floor","ceiling"}),
"You see nothing special.\n");
  AddReadMsg(({"blood","walls","wall"}),
"For three, you see, cannot be free.\n");
  AddExit("east","./deep9");
  AddItem("/obj/torch",REFRESH_REMOVE);
  AddItem("/obj/money",REFRESH_REMOVE,
    (["Money":MONEY_DEMON->CreateMoney((random(6)+5),({"copper"}))]));
}
