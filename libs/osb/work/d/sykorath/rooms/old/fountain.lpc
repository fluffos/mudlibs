// part of the town
// made by magictcs - 23 jun 97

// TODO: add exits
// TODO: add a search command for search fountain
// TODO: allow throwing of money into the fountain
// TODO: make more than wet feet if you enter the fountain
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//***********
// a fountain
//***********
void fountain() {
  tell_room(TO,"Suddenly the fountain explodes into a huge flood.\n");
  call_out("fountain",30);       // restart again and again
}

//*********************
// enter basin,fountain
//*********************
int enter(string str) {
  if (!str) return 0;
  if (member(({"basin","small basin","fountain","little fountain"}),
    str)!=-1) {
    write("As you enter the "+str+", you got wet feet.\n");
    return 1;
  }
  return 0;
}

//************
// drink water
//************
int drink(string str) {
  string norm;
  int drink;
  notify_fail("You can drink water from fountain.\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (member(({"water from fountain","water from little fountain"}),
    norm)!=-1) {
    drink=TP->QueryDrink();
    if (TP->QueryMaxDrink()<=drink) {
      write("You can't drink anymore!\n");
      say(NAME+" tries to drink water from fountain, but fails.\n");
      return 1;
    }
    drink+=10;
    if (drink>=TP->QueryMaxDrink()) drink=TP->QueryMaxDrink();
    TP->SetDrink(drink);
    write("You drink some water from the fountain.\n");
    say(NAME+" drinks some water from fountain.\n");
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A fountain");
  SetIntLong(
    "You are standing near a small basin with a little fountain it it.\n"
    "the fountain looks very beautiful.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"basin","small basin"}),#'IntLong);
  AddDetail(({"fountain","little fountain"}),
    "Sometimes the fountain explodes into a huge ones. It is nearly the\n"
    "same as a geyser.\n");
  AddDetail("geyser","You can see it from time to time.\n");

  /* commands */
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("drink",#'drink);

  /* exits */
  AddExit("southeast","./poststreetw1");
}

//******************
// stop the fountain
//******************
void notify_leave(object dest,int method,mixed extra) {
  ::notify_leave(dest,method,extra);
  if (interactive(PO)) {
    if (find_call_out("fountain")!=-1) {
      while (remove_call_out("fountain") != -1);       // stop fountain
    }
  }
}

//*******************
// start the fountain
//*******************
void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (interactive(PO)) {
    if (find_call_out("fountain")==-1) {
      call_out("fountain",30);     // show fountain
    }
  }
}

