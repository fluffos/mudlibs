inherit "std/room";

create() {
  ::create();
  SetIntShort("Dead End");
  SetIntLong(
"You have come to a dead end in the maze. The only exit is back south.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"end","dead end","maze"}),#'IntLong);
  AddDetail(({"exit"}),"It leads back south.\n");
  AddExit("south","./maze2");
}
