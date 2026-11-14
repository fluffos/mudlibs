#include "path.h"
inherit "std/room";

try_north() {
  write("You try to go north but bang your head against the door! Can't you read?\n");
  write("You'll have to wait for the re-opening!\n");
  return 1;
}

void create() {
  ::create();
  SetIntShort("Skid Row");
  SetIntLong(
"As you walk along trying not to make eye contact with any "
"of the street people around you, you notice the boarded-up "
"husk of the old Paradise Theater to your north, there is a "
"sign on the door that reads:\n"
"   GRAND RE-OPENING, COMING SOON!!!\n"
"To the south lies a small, shabby building.\n");
  AddExit("west", "./row5");
  AddExit("east", "./row7");
  AddExit("south", RANDY("orphan"));
  AddExit("north", #'try_north);
  HideExit("north",1);
  SetIndoors(0);
}
