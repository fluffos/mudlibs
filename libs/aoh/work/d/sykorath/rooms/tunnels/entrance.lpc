// made by magictcs - 4 aug 97
// special entrance to the tunnel system
// place the room below the earth!

// TODO: add more details and description
// TODO: code the rooms to the north

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

// if exit to the north is closed --> closed=1
int closed=1;

//******************
// property handling
//******************
int SetClosed(int c) { closed=c; return closed; }
int QueryClosed() { return closed; }

//****************************
// detect entering of a player 
//****************************
// if a player enters the room, the slave will be notified, he will dig into
// the stone, and after 2 minutes, he will open a tunnel,
// the tunnel is closed after two additional minutes by falling rocks
void notify_enter(object oldenv,int method,mixed extra) {
  object ob;
  ::notify_enter(oldenv,method,extra);
  if (interactive(PO)) {
    ob=present("_dig_slave_");
    // notify the slave about the new player
    if (ob) ob->notify_new_player();
  }
}

//**********
// open exit
//**********
// called by the slave!
void open_exit() {
  if (closed) {
    closed=0;
    HideExit("north",0);                   // show the exit
    tell_room(TO,"The slave finished his work to dig the rocks.\n");
    call_out("close_exit",120);            // close the exit after 2 mins
  }
}

//***********
// close exit
//***********
void close_exit() {
  tell_room(TO,
    "You hear a loud rumble. Some rocks are falling down from the ceiling. "
    "The exit to the north is blocked by massive rocks.\n");
  HideExit("north",1);
  closed=1;
}

//*********************************
// closure to bound for exit north!
//*********************************
int go_north() {
  if (!closed) {
    return TP->move(SYKORATH("nowhere"),M_TELEPORT,"enters the tunnel");
  }
  return ME_NO_MOVE;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A dead end");
  SetIntLong(
    "This is a dead end. No way leads further into the rocks.\n");
  SetIndoors(1);
  Set(P_REGION,REGION_JUNGLE);
  SetCoordinates( ({ ({0,0,-6}), C_SYKORATH }));  // under the earth!

  /* details */
  AddDetail(({"end","dead end"}),#'IntLong);

  /* objects */
  AddItem(NPC("digslave"),REFRESH_HOME);

  /* exits */
  AddExit("north",#'go_north);
  HideExit("north",1);             // hide the exit
  AddNowayMsg("north","Some slaves are working to dig this way.\n");
  SetNowayMsg("You bang your head against the next wall.\n");
// TODO: add another exit
  AddExit();
}

