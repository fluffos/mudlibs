inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a twisty maze of little passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","twisty maze","little maze","little passages",
	      "little passage","twisty passage","twisty passages",
	      "twisty little passages","twisty little passage"}),#'IntLong);
  AddExit("south","./maze1");
  AddExit("east","./maze4");
}
