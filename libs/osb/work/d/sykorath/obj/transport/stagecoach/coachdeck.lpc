// a room for the stage coach
// made by magictcs - 18 jul 97

// TODO: add more details and so on

#include <properties.h>
#include <sykorath.h>

inherit "/std/room";

// overload leave command (because it is not a ship :(
// bad mudlib :((
int cmd_leave(string str) {
  if (Query(P_HARBOUR)) return 0;   // calls:   ship::cmd_leave(str);
  write(
  "The stage coach is a little bit to fast. Better wait until is stops on\n"
  "the next station!\n");
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("In the stage coach");
  SetIntLong(
  "You are sitting in the stage coach, while waiting for the next station.\n");
  SetIndoors(1);
  AddRoomCmd("leave","cmd_leave");
}

