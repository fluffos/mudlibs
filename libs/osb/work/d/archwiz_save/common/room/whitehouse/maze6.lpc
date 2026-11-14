inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a passage of a twisty little maze, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"passage","little maze","maze","twisty maze",
	      "twisty little maze","little passage","little passages",
	      "twisty passages","twisty passage",
	      "twisty little passages","twisty little passage"}),
    #'IntLong);
  AddExit("north","./maze5");
  AddExit("south","./maze8");
  AddExit("west","./maze10");
  AddExit("east","./maze9");
}
