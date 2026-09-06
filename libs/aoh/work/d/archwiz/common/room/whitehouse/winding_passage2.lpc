inherit "std/room";

create() {
  ::create();
  SetIntShort("Winding Passage");
  SetIntLong(
"This is a winding passage. It seems that there are only exits on\n\
the east and south.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"winding passage","passage"}),#'IntLong);
  AddExit("south","./mirror_room2");
  AddExit("east","./cave2");
}
