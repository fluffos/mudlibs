inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a passage of a little twisty maze, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","passage","little maze","twisty maze",
	      "little twisty maze","little passage","little twisty passage",
	      "twisty passage","little passages","twisty passages",
	      "little twisty passages"}),#'IntLong);
  AddExit("up","./maze14");
  AddExit("west","./maze8");
  AddExit("east","./maze6");
}
