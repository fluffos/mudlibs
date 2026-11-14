inherit "std/room";

create() {
  ::create();
  SetIntShort("Maze in the white house");
  SetIntLong("This is a little maze of twisty passages, all alike.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"maze","little maze","twisty passages","twisty passage",
	      "passages","passage"}),#'IntLong);
  AddExit("up","./grating_room");
  AddExit("down","./maze9");
  AddExit("south","./maze10");
  AddExit("west","./maze8");
}
