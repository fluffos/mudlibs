inherit"std/room";
#include "path.h"
#include <rooms.h>

void create() {
  ::create();
  SetIntShort("Village shore");
  SetIntLong(
"The village shore. A jetty leads out to the east. To the north some stairs "
"lead up to a large hill. A road starts out to the west. Above you is "
"the metal structure of an old C.A.R.T. station. An iron stairway leads up. "
"Further to the west you can see the large structure of Nightfall City, the "
"capital of this world. To the south there seems to be a small harbour.\n");
  AddExit("west", "./jetty");
  AddExit("east", "./jetty2");
  AddExit("south",PORT("nf_port"));
  AddExit("up",   CART("beach"));
  AddExit("north",PHISH("hill"));
  AddItem(PIROBJ("paper"),REFRESH_REMOVE);
  AddDetail(({"station", "C.A.R.T. station", "CART station"
             , "C.A.R.T.", "CART" })
           ,
"An old station of the C.A.R.T. network. Two lines of rail tracks lead away "
"from the station and vanish underground. However, you can't reach them from "
"your current position.\n"
           );
  AddDetail(({"rail", "rails", "rail track", "rail tracks"
             , "track", "tracks" })
           ,
"The rail tracks lead off the station north and west, vanishing undergrund "
"in some distance. They don't appear being used still, and in fact look "
"a bit rusty.\n"
           );
  SetIndoors(0);
}

