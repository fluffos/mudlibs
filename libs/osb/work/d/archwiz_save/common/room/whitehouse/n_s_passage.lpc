inherit "/std/room";

create() {
  ::create();
  SetIntLong(
"This is a high north-south passage, which forks to the southeast.\n");
  SetIntShort("North-South Passage");
  SetIndoors(1);
  AddDetail(({"passage","high passage","north-south passage",
	      "high north-south passage"}),#'IntLong);
  AddExit("south","./chasm");
  AddExit("north","./round_room");
  AddExit("southeast","./canyon");
}
