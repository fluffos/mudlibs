inherit "std/room";

create() {
  ::create();
  SetIntShort("Cave with engravings");
  SetIntLong(
"This is a small cave with some engravings on the wall. The cave is "
"quite dry. The only exit is back to the southwest.\n");
  AddDetail(({"cave","small cave"}),#'IntLong);
  AddDetail(({"walls","wall"}),"The walls are covered with engravings.\n");
  AddDetail(({"engravings","engraving"}),
    "You try hard, but can't make any sense of them.\n");
  AddReadMsg(({"engravings","engraving"}),
    "You try hard, but you can't make any sense of them.\n");
	SetIndoors(1);
	SetBright(-10);
	AddExit("southwest","./round_room");
}

