inherit "std/room";

create() {
  ::create();
  SetIntShort("Dead End");
  SetIntLong(
"You have come to a dead end in the maze. The only exit is back west.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"end","dead end"}),#'IntLong);
  AddDetail(({"exit"}),"It leads back west.\n");
  AddExit("west","./skeleton_room");
}
