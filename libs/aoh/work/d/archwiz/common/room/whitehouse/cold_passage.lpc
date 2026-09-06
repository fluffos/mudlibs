inherit "/std/room";

create() {
  ::create();
  SetIntLong(
"This is a cold and damp corridor where a long east-west passageway "
"turns into a northward path.\n");
  SetIntShort("Cold Passage");
  SetIndoors(1);
  AddDetail(({"passage","cold passage","cold corridor","corridor",
	      "damp corridor","long passageway","passageway",
	      "east-west passageway","northward path","path"}),
	      #'IntLong);
  AddExit("north","./mirror_room2");
  AddExit("west","./slide_room");
}
