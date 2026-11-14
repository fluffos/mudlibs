#include <moving.h>
#include <rooms.h>
#include <combat.h>
#include <properties.h>

inherit "std/room";

create() {
  ::create();
  SetIntShort("Atlantis Room");
  SetIntLong(
"This is an ancient room, long under water. There is an exit to "
"the north and a staircase leading up.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"staircase","stairs"}),
    "Actually, the staircase are huge, rough steps hewn into the bare rock.\n");
  AddDetail(({"steps","step","huge steps","rough steps","rough step",
    "huge step","huge, rough step","huge, rough steps"}),
    "You think that it must have been hard labour to make these steps.\n");
  AddDetail(({"rock","bare rock","natural rock"}),
    "Just rock.\n");
  AddDetail(({"room","ancient room"}),#'IntLong);
  AddExit("north","./reservoir_south");
  AddExit("up","./cave2");
  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT: "a crystal trident",
      P_LONG:
"The trident is made of a blue shimmering crystal. Some moss is hanging "
"on the top ends of the weapon. The hilt is a bit slimy.\n",
      P_IDS: ({"trident","klabauter_trident"}),
      P_ADS: ({"a","crystal"}),
      P_NUMBER_HANDS: 2,
      P_WC: 14,
      P_WEIGHT: 5000,
      P_VALUE: 500,
      P_QUALITY: 100,
      P_SIZE:PSIZE_SMALL,
      P_WEAPON_TYPE:WT_INFANTRY,
      P_DAM_TYPE:DT_PIERCE]) );
}
