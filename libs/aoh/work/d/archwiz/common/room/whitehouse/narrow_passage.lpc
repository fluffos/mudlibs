inherit "std/room";

create() {
  ::create();
  SetIntShort("Narrow Passage");
  SetIntLong(
"This is a long and narrow corridor where a long north-south "
"passageway briefly narrows even further.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"passage","narrow passage","long passage","long corridor",
	      "narrow corridor","corridor"}),#'IntLong);
  AddDetail(({"long passageway","passageway","north-south passageway",
	      "long north-south passageway"}),
    "The passageway gets more and more narrow.\n");
  AddExit("south","./round_room");
  AddExit("north","./mirror_room1");
}
