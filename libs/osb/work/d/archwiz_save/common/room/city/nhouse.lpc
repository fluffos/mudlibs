inherit "std/room";

#include "path.h"
#include <moving.h>

int ajar;

int enter(string str) {
  if (!str) return 0;
  if (str!="house" && str!="window") return 0;
  if (ajar!=2) {
    write("The window is not opened wide enough.\n");
    return 1;
    }
  write("You enter the white house.\n");
  this_player()->move(WHITEHOUSE("whkitchen"),M_GO,"into the house");
  return 1;
}

int close(string str) {
  if ((!str) || (str!="window")) return 0;
  return (int) notify_fail(
   "You have to be inside the house to do that.\n") && 0;
}

int open(string str) {
  if ((!str) || (str!="window")) return 0;
  if (!ajar) return (int) notify_fail(
    "You can't open it from here.\n") && 0;
  if (ajar==2)  return (int) notify_fail(
    "It IS open, cretin!\n") && 0;
  if (this_player()->QueryStr()<0) return (int) notify_fail(
"You try hard to open the window, but you are not strong enough to move it. "
"Perhaps someone else could help you?\n") && 0;
  write ("With great effort you manage to open the window.\n");
  ajar=2;
  return 1;
}

int close_window() {
  ajar=0;
  return 1;
}

int open_window() {
  ajar=2;
  return 1;
}

int query_window() { return ajar; }

QueryIntLong() {
  string desc;
  desc="You are behind a white house. In one corner of the house there is a "
"window which is ";
  switch(ajar) {
     case 1: desc=desc+"slightly ajar.\n"; break;
     case 2: desc=desc+"open.\n"; break;
     default: desc=desc+"closed.\n";
  }
  return desc;
}

string windowstatus() {
  string desc;
  desc = "It is ";
  switch (ajar) {
     case 1: desc=desc+"slightly ajar.\n"; break;
     case 2: desc=desc+"open.\n"; break;
     default: desc=desc+"closed.\n";
  }
  return desc;
}

create() {
  ::create();
  SetIntShort("Behind a white house");
  SetIndoors(0);
  AddDetail("windows","They are all barred. You can't break them open.\n");
  AddDetail("window",#'windowstatus);
  AddDetail(({"white house","house"}),#'IntLong);
  AddDetail(({"corner","corner of the house"}),
    "A window is there.\n");
  AddRoomCmd("open",#'open);
  AddRoomCmd("close",#'close);
  AddExit("north","./clearing2");
  AddExit("southwest","./whouse");
  AddExit("enter",#'enter);
  HideExit("enter",1);
  reset();
}

reset() {
  ::reset();
  ajar=1;
}
