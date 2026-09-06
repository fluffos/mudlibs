inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a little passage of a twisty maze, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little maze","twisty maze","little twisty maze",
	      "passage","little passage","twisty passage",
	      "passages","little passages","twisty passages",
	      "little twisty passages","little twisty passage"}),
    #'IntLong);
  AddExit("down","./maze10");
  AddExit("south","./maze9");
  AddExit("west","./maze14");
  AddExit("east","./maze6");
}
