inherit "std/room";

#include "path.h"
#include <moving.h>

int open,taken;

open(string str) {
  string a;
  object ob;
  if (!this_player()) return 0;
  if (!str) return 0;
  a=lower_case(str);
  if (a!="door" && a!="mailbox") return;
  if (a=="door") {write("You can't break it open!\n"); return 1; }
  if (open) {write("It is already open.\n"); return 1; }
  if (taken) {write("You open the mailbox. It is empty.\n"); return 1; }
  write("As you open the mailbox, a leaflet falls out.\n");
  ob = clone_object(OBJ("leaflet"));
  ob->move((environment(this_player())), M_SILENT);
  open=1;
  taken=1;
  return 1;
}

close(string str) {
  string a;
  a=lower_case(str);
  if (a!="mailbox") return;
  if (!open) {write("It's still closed.\n"); return 1; }
  write("You close the mailbox.\n");
  open=0;
  return 1;
}

look_box() {
  if (open) return "It is open.\n";
  return "It's closed.\n";
}

create() {
 ::create();
 SetIntShort("West of white house");
 SetIntLong(
"You are in an open field west of a big white house with a boarded front "
"door. There is a small mailbox here.\n");
 SetIndoors(0);
  AddDetail(({"mailbox","box","small mailbox",
              "small box","mail box"}),
#'look_box);
 AddDetail("door","It's boarded.\n");
 AddExit("northeast","./nhouse");
 AddExit("southeast","./shouse");
 AddRoomCmd("open",#'open);
 AddRoomCmd("close",#'close);
 reset();
}

reset() {
  ::reset();
  open=0;
  if (!present("leaflet",this_object())) taken=0;
}
