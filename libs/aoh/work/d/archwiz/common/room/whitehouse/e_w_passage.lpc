inherit "/std/room";

create() {
  ::create();
  SetIntLong(
"This is a narrow east-west passageway. There is a narrow stairway "
"leading down at the south end of the room.\n");
  SetIntShort("East-West Passage");
  SetIndoors(1);
  AddDetail(({"narrow stairs","narrow stairway","stairs","stairway"}),
    "Actually, its a flight of steps hewn into the sloping floor.\n");
  AddDetail(({"passage","east-west passage","passageway",
	      "east-west passageway"}),#'IntLong);
  AddExit(({"down","south"}),"./chasm");
  HideExit("down",1);
  AddExit("east","./round_room");
  AddExit("west","./trollroom");
}
