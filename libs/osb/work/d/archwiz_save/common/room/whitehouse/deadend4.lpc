inherit "std/room";

create() {
  ::create();
  SetIntShort("Dead End");
  SetIntLong(
"You have come to a dead end in the maze. The only exit is back west.\n");
  SetIntNoise("You here something roaring in the distance.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"end","dead end"}),#'IntLong);
  AddDetail(({"maze","twisty maze"}),
    "You're still lost in a twisty maze.\n");
  AddDetail(({"exit","narrow exit"}),
    "The exit is narrow. You wonder how you've passed it.\n");
  AddExit("west","./maze13");
}
