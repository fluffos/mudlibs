inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a twisty passage of a little maze, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","passage","twisty passage","little maze"}),#'IntLong);
  AddExit("up","./maze6");
  AddExit("north","./deadend3");
  AddExit("west","./maze14");
  AddExit("east","./maze8");
}
