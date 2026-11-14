inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a little twisty passage of a maze, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little passage","passage","twisty passage",
	      "little twisty passage"}),#'IntLong);
  AddExit("south","./maze7");
  AddExit("west","./maze12");
}
