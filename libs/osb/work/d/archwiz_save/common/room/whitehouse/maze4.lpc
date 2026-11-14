inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a little maze of twisty passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little maze","twisty maze","little passage",
	      "little passages","twisty passages","twisty passage"}),
    #'IntLong);
  AddExit("north","./maze2");
  AddExit("west","./skeleton_room");
  AddExit("up","./maze3");
}
