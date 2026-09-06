// part of the city
// made by magictcs - 13 jul 97

// TODO: adapt exits west
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//*************
// enter bridge
//*************
int enterbridge() {
  if (call_other(SYKORATH("westgate"),"QueryBridge")=="closed") {
    show(NAME+" tries to go east, but fails.\n");
    return 0;
  }
  write("You step onto the drawbridge.\n");
  TP->move(SYKORATH("drawbridge"),M_GO,"steps onto the drawbridge.\n");
  return ME_OK;
}

//**********
// ring bell
//**********
int ring(string str) {
  notify_fail("Ring what?\n");
  if (!str) return 0;
  if (member(({"bell","copper bell","bell on staff","copper bell on staff",
    "bell of wodden staff","copper bell of wooden staff"}),str)!=-1) {
    write("You ring the bell: Ding Ding - a very clear sound.\n");
    show(NAME+" rings the bell.\n");
    if (call_other(SYKORATH("westgate"),"QueryBridge")!="closed") {
      write("But nothing happens.\n");
      return 1;
    }
    call_other(SYKORATH("westgate"),"SetBridge","open");
    call_other(SYKORATH("westgate"),"openbridge");
    tell_room(TO,"The drawbridge opens.\n");
    return 1;
  }
  return 0;
}

//********
// details
//********
string lookbridge() {
  string closed;
  closed=call_other(SYKORATH("westgate"),"QueryBridge");
  return "A huge drawbridge leads into Sykorath.\n"
    "The drawbridge is "+closed+".\n";
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("On a path.\n");
  SetIntLong(
    "You are standing on a small path. To the east you see a drawbridge.\n"
    "A bell hangs on a staff here.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"path","small path"}),#'IntLong);
  AddDetail("drawbridge",#'lookbridge);
  AddDetail("east",
    "To the east lies Sykorath, one of the oldest cities in this world. You\n"
    "can go there by using the drawbridge.\n");
  AddDetail("sykorath",
    "Sykorath is a huge city, and one of the oldest in this world. You can\n"
    "explore many new things there.\n");
  AddVItem( ([
    P_IDS:  ({"staff"}),
    P_ADS:  ({"wooden staff"}),
    P_LONG: "It is a wooden staff. A small bell hangs on it. You wonder what "
            "the bell is good for.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"bell"}),
    P_ADS:  ({"copper"}),
    P_LONG: "The bell is made of copper. You don't know what the bell is good "
            "for, but it looks like that it will ring very clear.\n"
            "It hangs on a wooden staff.\n",
    P_NOGET: "The bell is stuck to the staff.\n", ]) );

  /* commands */
  AddRoomCmd("ring","ring");

  /* exits */
  AddExit("east",#'enterbridge);
  AddNowayMsg("east","You can't go east. The drawbridge is pulled up.\n");
}

