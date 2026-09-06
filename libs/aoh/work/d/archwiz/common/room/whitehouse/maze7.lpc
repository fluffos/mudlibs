inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a little twisty maze of passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little twisty maze","passages","passage",
	      "twisty maze","twsity passage","twisty passages",
	      "little maze","little passage","little passages",
	      "twisty little passage","twisty little passages"}),
    #'IntLong);
  AddExit("up","./maze11");
  AddExit("south","./maze12");
  AddExit("west","./maze5");
  AddExit("east","./maze13");
}
