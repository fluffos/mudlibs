#include "path.h"

inherit "std/room";

int drink(string arg) {
  if (arg == "water" || arg == "from fountain")
  { write("The water is wonderfully refreshing.\n");
    return 1;
  }
  else
    return 0;
}

void create() {
  ::create();
  SetIntShort("Ruins of the atrium");
  SetIntLong(
"This once was a pretty atrium with a ceiling made of glass. "
"Now you can see shards of glass lying around everywhere "
"and the fountain in the middle of the room is worn down. "
"But there are still birds playing here and you are surrounded "
"by flowers of all kinds. You sense that this is still a place "
"of peace.\n"
            );
  AddDetail("birds","Many colourful birds of different species.\n");
  AddDetail("flowers","Beautiful flowers of all kinds are growing here.\n");
  AddDetail("fountain",
            "The fountain is still bubbling with fresh clear water.\n");
  AddExit("west", "./psi_ruins2");
  AddRoomCmd("drink",#'drink);
  SetIntNoise("You can hear the water sparkling from the fountain.\n");
  SetIndoors(0);
}
