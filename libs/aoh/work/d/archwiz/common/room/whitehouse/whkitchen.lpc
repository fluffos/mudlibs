inherit "std/room";

#include "path.h"
#include <rooms.h>
#include <moving.h>

int ajar,sack,bottle;

#define OUTSIDE_ROOM (CITY("nhouse"))

int leave(string str) {
  ajar = OUTSIDE_ROOM->query_window();
  if ((!str) || (str!="through window")) return (int) notify_fail(
    "Leave through what?\n") && 0;
  if (!ajar) return (int) notify_fail("The window is closed.\n") && 0;
  this_player()->move(OUTSIDE_ROOM,M_GO,"through the window");
  return 1;
}

int close(string str) {
  if (!str) return 0;
  if (str!="window") return 0;
  if (!this_player()) return 0;
  ajar=OUTSIDE_ROOM->query_window();
  if (ajar==0) {
    write("It IS closed, cretin!\n");
    return 1;
    }
  if (this_player()->QueryStr()<2) return (int) notify_fail(
"You try hard to close the window, but it seems as if you are not strong\n"
"enough. You should try to find someone to help you.\n") && 0;
  write("You close the window.\n");
  OUTSIDE_ROOM->close_window();
  return 1;
}

int open(string str) {
  if (!str) return 0;
  if (str!="window") return 0;
  ajar=OUTSIDE_ROOM->query_window();
  if (ajar==2) {
    write("It IS open, cretin!\n");
    return 1;
    }
  if (this_player()->QueryStr()<2) return (int) notify_fail(
"You try hard to open the window, but it seems as if you are not strong\n"
"enough. You should try to find someone to help you.\n") && 0;
  write ("You open the window.\n");
  OUTSIDE_ROOM->open_window(); 
  return 1;
}

int take(string str) {
  object ob;
  if (!str) return 0;
  str = explode(norm_id(str), " ")[0];
  if (str != "bottle" && str != "sack") 
    return 0;
  if (str=="sack" && sack==0) return 0;
  if (str=="sack") {
     ob=clone_object(OBJ("sack"));
     ob->move(this_object(),M_SILENT);
     sack=0;
  }
  return 0;
}

QueryIntLong() {
  string desc;
  desc=
"You are in the kitchen of the white house. A table seems to have been used "
"recently for the preparation of food. A passage leads to the south, and a "
"a dark staircase can be seen leading upward. To the north is a small window "
"which is ";
  ajar=OUTSIDE_ROOM->query_window();
  switch(ajar) {
     case 1: desc=desc+"slightly ajar.\n"; break;
     case 2: desc=desc+"open.\n"; break;
     default: desc=desc+"closed.\n";
     }
  if (sack) 
    desc=desc+
      "On the table is an elongated brown sack, smelling of hot peppers.\n";
  return desc;
}

create() {
  ::create();
  SetIntShort("Kitchen of a white house");
  SetIndoors(1);
  AddDetail("table","There is nothing special about the table.\n");
  AddDetail("sack","It's long and brown.\n");
  AddDetail(({"window","small window"}),
    "Probably you could leave the house there.\n");
  AddDetail(({"kitchen","room"}),#'IntLong);
  AddDetail(({"house","white house"}),
    "You're inside the white house.\n");
  AddDetail(({"passage","normale passage"}),
    "Just a pretty normal passage leading south into the living room.\n");
  AddDetail(({"staircase","stairs","dark staircase","dark stairs"}),
    "You may go upstairs there.\n");
  AddRoomCmd("open",#'open);
  AddRoomCmd("close",#'close);
  AddRoomCmd(({"get","take"}),#'take);
  AddExit("leave",#'leave);
  HideExit("leave",1);
  AddExit("south","./living_room");
  AddExit("up","./h_attic");
  AddItem(MONSTER("woman"),REFRESH_HOME);
  reset();
}

reset() {
  ::reset();
  sack=1;
}
