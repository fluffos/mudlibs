#include "path.h"
#include <moving.h>

inherit "/std/room";

int co,tt;

no() {
  write("Number: "); write(co); write("\n");
  return 1;
}

correct() {
  write("Right.\n");
  co++;
}

QueryIntLong() {
  if (co && tt) return
"You're in a small cavern. Again, there is a face on the wall and a sign. "
"There is a magic field. Perhaps you could enter it?\n";
  return
"You're in a small cavern. Again, there is a face on the wall and a sign.\n";
}

int answer(string str) {
  if (!str) return (int) notify_fail(
    "Answer what?\n") && 0;
  if (!this_player()) return 0;
  switch (co) {
    case 1: if (str=="water") correct();break;
    case 2: if (str=="lie") correct();break;
    case 3: if ((str=="slave") || (str=="prisoner")) correct();break;
    case 4: if ((str=="gold")||(str=="coins")||(str=="money")) correct();break;
    case 5: if (str=="hate") correct();break;
    case 6: if ((str=="rooster")||(str=="cock")) correct();break;
    case 7: if (str=="large") correct();break;
    case 8: if (str=="early") correct();break;
    case 9: if (str=="free") correct();break;
    case 10: if (str=="women") {
	     correct();
	     write("This was the last one!\n");
	     co=tt=1;
	     write("A magic field appears. It can be entered.\n");
	     break;
	     }
    default: write("WRONG!\n");
    }
  return 1;
}


int enter(string str) {
  if (!str) return 0;
  if ((str!="field")||(tt!=1)) return (int) notify_fail(
    "Enter what?\n") && 0;
  write("You enter the field.\n");
  if (!this_player()) return 0;
  this_player()->move(PIRATE("troom"),M_GO,"into the field");
  tell_room(this_object(),"The magic field disappears.\n");
  tt=0;
  return 1;
}

int east() {
  write(
"As you go to the east, you step on an unseen square field on the ground. "
"A magic field appears and transports you away.\n");
  co=1;
  this_player()->move(PIRATE("deep2"),M_GO,"east");
  return 1;
}

create() {
  ::create();
  SetIntShort("cavern");
  AddReadMsg(({"sign"}),
"Now 'answer' me the 10 keywords to gain access to the treasure room. "
"Enter the words separately. Start with the first one! "
"Enter 'no' to receive the number of the keyword you have to enter.\n");
  AddDetail("sign","There is something written on it.\n");
  AddDetail(({"cavern","room"}),QueryIntLong());
  AddDetail("face","It looks pretty normal.\n");
  AddDetail(({"walls","wall","ceiling","ground","floor"}),
"You are in a small room.\n");
  SetIndoors(1);
  SetBright(0);
  AddRoomCmd("no",#'no);
  AddRoomCmd("answer",#'answer);
  AddExit("enter",#'enter);
  HideExit("enter",1);
  AddExit("east",#'east);
  reset();
}

reset() {
  ::reset();
  if (tt==1) tell_room(this_object(),"A magic field vanishes.\n");
  tt=0;
  co=1;
  tell_room(this_object(),
    "The face speaks: I'm getting impatient, let's start over again.\n");
}
