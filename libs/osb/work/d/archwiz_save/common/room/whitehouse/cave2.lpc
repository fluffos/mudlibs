inherit "std/room";

create() {
  ::create();
  SetIntShort("Cave");
  SetIntLong(
"This is a tiny cave with entrances west and south, and a dark, "
"forbidding staircase leading down.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"staircase","forbidding staircase","dark staircase",
	      "forbidding, dark staircase","dark, forbidding staircase"}),
    "Actually, the staircase are huge, rough steps hewn into the bare rock.\n");
  AddDetail(({"steps","huge steps","rough steps","huge, rough steps"}),
    "You think that it must have been hard labour to make these steps.\n");
  AddDetail(({"cave","tiny cave"}),#'IntLong);
  AddDetail(({"entrance","entrances"}),
    "The entrances lead west and south.\n");
  AddExit("south","./mirror_room2");
  AddExit("west","./winding_passage2");
  AddExit("down","./atlantis_room");
}
