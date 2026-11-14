#include <money.h>
#include <rooms.h>
#include "path.h"

inherit "std/room";

void create() {
  ::create();
  SetIntShort("The bank");
  SetIntLong(
"This is the headquarter of the CityBank(tm). A large counter fills half "
"of the room. Here you can deposit your money if you open an account. "
"Ask the teller, if you want to know more! There is an exit to the west.\n");
  SetIndoors(1);
  AddDetail(({"headquarter","citybank","bank","city bank","room"}),
QueryIntLong());
  AddDetail(({"counter","wooden counter"}),"The counter is made of wood.\n");
  AddDetail(({"wood","polished wood"}),
"It is polished wood, but you have no idea of which sort of tree.\n");
  AddDetail("exit","It leads to the west.\n");
  AddExit("west", "./narr_alley");
  AddItem( BANK_TELLER, REFRESH_HOME);
}
