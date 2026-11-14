// made by magictcs - 8 aug 97
// a room for climbing down the well
// no extra exit to this room, the player is moved into this room by
// the well.c and he leaves the room automatically!!
// the room is autodestructing after the player left the room!

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <rope.h>
#include <sykorath.h>

inherit "/std/container";

int count;

string *d=({
  "You use the next handle to climb down.\n",
  "And the next handles...\n",
  "It becomes brighter.\n",
  "Ups, one handle is slightly damaged.\n",
  "One of the last handles...\n",
  });

//**********************
// climb down callout :)
//**********************
void climb_down(int c,object pl) {
  if (!pl) return;
  if (c==5) {
    tell_object(pl,"You jump the last metres to the ground.\n");
    pl->move(SEAROOMS("beach2"),M_GO);
    return;               // stop the climbing
  }
  tell_object(pl,d[c]);
  call_out("climb_down",2,c+1,pl);
}

//***********************
// special Short and Long
//***********************
string QueryIntShort() {
  return "Inside a long tube down.\n";
}

string QueryIntLong() {
  return "You are climbing down inside a long tube.\n";
}

//*******
// create
//*******
create() {
  ::create();
  count=0;
  SetIndoors(1);
  SetMaxWeight(1000000);
  ForbidAllMagic();         // working ???
}

// a special output that you are climbing down and down and down and jump
// the last metres to the ground!
void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (!interactive(PO)) return;
  write("The handles are very slippery - be carefully!\n");
  // start the call_out
  call_out("climb_down",2,0,TP);
}

// removes the object if the player is moved out on another way!
void notify_leave(object dest,int method,mixed extra) {
  ::notify_leave(dest,method,extra);
  if (!interactive(PO)) return;
  call_out("remove",1);
}

