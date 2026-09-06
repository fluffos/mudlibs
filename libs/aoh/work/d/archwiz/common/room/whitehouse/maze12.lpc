inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a twisty little passage of a maze, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","twisty little passage","passage",
	      "twisty passage","little passage"}),#'IntLong);
  AddExit("up","./cyclops_room");
  AddExit("south","./maze7");
  AddExit("west","./maze11");
}
