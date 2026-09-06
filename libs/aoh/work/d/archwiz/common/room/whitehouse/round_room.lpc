inherit "std/room";

int cavein() {
  return (int) notify_fail(
    "After a short walk you come to a dead end and return.\n") && 0;
}

create() {
  ::create();
  SetIntShort("Round Room");
  SetIntLong(
"This is a circular stone room with passages in all eight directions. "
"Several of them have unfortunately been blocked by cave-ins.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"stone room","circular room","room","circular stone room"}),
    #'IntLong);
  AddDetail(({"stone"}),"Not very interesting.\n");
  AddDetail(({"passages","passage"}),
    "Passages lead in every direction.\n");
  AddDetail(({"cave-ins","cave-in"}),"Cave-ins block some passages.\n");
  AddExit(({"southeast","northwest","southwest"}),#'cavein);
  AddExit("south","./n_s_passage");
  AddExit("north","./narrow_passage");
  AddExit("east","./loud_room");
  AddExit("west","./e_w_passage");
  AddExit("northeast","./engravings_cave");
}
