inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a twisty little maze of passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little maze","little passage","twisty passage",
	      "little passages","twisty passages","twisty little passage",
	      "twisty little passages","twisty maze","twisty little maze"}),
    #'IntLong);
  AddExit("up","./maze6");
  AddExit("down","./skeleton_room");
  AddExit("west","./maze5");
  AddExit("east","./maze7");
}
