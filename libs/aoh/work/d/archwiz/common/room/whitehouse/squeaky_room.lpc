inherit "/std/room";

create() {
  ::create();
  SetIntLong(
"You are in a small room. Strange squeaky sounds may be heard "
"coming from the passage at the south end. You may also escape to the "
"east.\n");
  SetIntShort("Squeaky Room");
  SetIndoors(1);
  AddDetail(({"room","small room"}),#'IntLong);
  AddDetail(({"passage","dark passage"}),
    "It's just a dark passage leading south.\n");
  AddDetail(({"sounds","squeaky sounds","sound","squeaky sound",
              "strange sound","strange sounds","strange squeaky sounds",
	      "strange squeaky sound"}),
    "Just listen to it.\n");
  SetIntNoise("You hear strange squeaky sounds from the south.\n");
  AddNoise(({"strange squeaky sounds","strange squeaky sound","squeaky sound",
    "squeaky sounds","strange sound","strange sounds","sounds","sound"}),
    "It is to be heard from the passage at the south end.\n");
  AddExit("south","./bat_room");
  AddExit("east","./mine_entrance");
}
