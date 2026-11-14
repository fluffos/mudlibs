// part of the town
// made by magictcs - 9 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//*************
// clean mirror
//*************
int clean(string str) {
  if (!str) return 0;
  if (member(({"mirror","huge mirror"}),str)!=-1) {
    write("It is already cleaned!\n");
    return 1;
  }
  return 0;
}

//******
// sleep
//******
int sleep(string str) {
  notify_fail("Sleep where?\n");
  if (!str) return 0;
  if (member(({"bed","large bed","in bed","in large bed","on bed",
    "on large bed"}),norm_id(str))!=-1) {
    write("You can't sleep here, because you won't touch the bed!\n");
    show(NAME+" tries to sleep.\n");
    return 1;
  }
  return 0;
}

//******
// touch
//******
int touch(string str) {
  notify_fail("Touch what?\n");
  if (!str) return 0;
  if (member(({"bed","large bed"}),str)!=-1) {
    write("Touching the bed will not be a good idea!\n");
    show(NAME+" wants to touch the bed.\n");
    return 1;
  }
  return 0;
}

//****
// sit
//****
int sit(string str) {
  notify_fail("Sit where?\n");
  if (!str) return 0;
  if (member(({"bed","large bed","on bed","on large bed","down",
    "down on bed","down on large bed"}),norm_id(str))!=-1) {
    write("Better not, you will go in trouble if the owner comes back.\n");
    show(NAME+" tries to sit "+str+".\n");
    return 1;
  }
  return 0;
}

//******
// stand
//******
int stand() {
  notify_fail("You are not sitting!\n");
  return 0;
}

//*************
// smash mirror
//*************
int do_break(string str,string command) {
  if (member(({"mirror","huge mirror"}),str)!=-1) {
    write("The owner of this house will be very angry if you do this.\n"
      "You decide not to "+command+" the mirror.\n");
    return 1;
  }
  return 0;
}

int smash(string str) {
  notify_fail("What do you want to smash?\n");
  if (!str) return 0;
  return do_break(str,"smash");
}

int destroy(string str) {
  notify_fail("What do you want to destroy?\n");
  if (!str) return 0;
  return do_break(str,"destroy");
}

int breakmirror(string str) {
  notify_fail("What do you want to break?\n");
  if (!str) return 0;
  return do_break(str,"break");
}


//*****************
// gettake handling
//*****************
int gettake(string str) {
  string norm;
  if (!str) return 0;
  norm=norm_id(str);
  if (member(({"mirror","huge mirror"}),norm)!=-1) {
    write("You can't get the mirror. It is too heavy.\n");
    return 1;
  }
  if (member(({"frame","golden frame","frame of mirror",
    "golden frame of mirror","frame of huge mirror",
    "golden frame of huge mirror"}),norm)!=-1) {
    write(
      "How do you want to get the frame of a hanging mirror? Nice joke!\n");
    return 1;
  }
  return 0;
}

//************
// look mirror
//************
string lookmirror() {
  return 
  "You see a huge mirror with a golden frame.\n"
  "As you take a look into the mirror you see:\n"+
  TP->Long()+"Beautiful is all what you can say.\n";
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("In a huge house");
  SetIntLong(
    "You are standing in the bedroom of this house.\n"
    "A large bed stands here and a huge mirror hangs on the wall.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);
 
  /* details */
  AddDetail(({"house","huge house","bedroom"}),#'IntLong);
  AddDetail(({"bed","large bed"}),
    "You see a large bed. It is the one of the owner of this house.\n"
    "Better do not touch the bed! The owner will become angry.\n");
  AddDetail(({"wall","one wall"}),"A huge mirror hangs on it.\n");
  AddDetail("walls",
   "You see some walls, but one wall is more interesting than the others.\n");
  AddDetail(({"mirror","huge mirror"}),#'lookmirror);
  AddDetail(({"frame","golden frame","frame of mirror",
    "golden frame of mirror","frame of huge mirror",
    "golden frame of huge mirror"}),
    "The frame of the mirror is made of pure gold.\n");

  /* commands */
  AddRoomCmd("sleep",#'sleep);
  AddRoomCmd("touch",#'touch);
  AddRoomCmd("sit",#'sit);
  AddRoomCmd("stand",#'stand);
  AddRoomCmd("take",#'gettake);
  AddRoomCmd("get",#'gettake);
  AddRoomCmd("smash",#'smash);
  AddRoomCmd("destroy",#'destroy);
  AddRoomCmd("break",#'breakmirror);
  AddRoomCmd("clean",#'clean);

  /* exits */
  AddExit("south","./housew1");
}

