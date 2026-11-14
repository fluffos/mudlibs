inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a twisty little maze of passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","twisty little maze","twisty maze","little maze",
	      "passages","passage"}),#'IntLong);
  AddExit("west","./maze13");
  AddExit("south","./deadend4");
  AddExit("east","./maze7");
}
