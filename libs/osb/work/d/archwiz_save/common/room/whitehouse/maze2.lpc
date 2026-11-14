inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a maze of little twisty passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little passage","little passages","twisty passage",
	      "twisty passages","little twisty passage",
	      "little twisty passages"}),#'IntLong);
  AddExit("north","./maze1");
  AddExit("west","./maze4");
  AddExit("east","./deadend1");
}
