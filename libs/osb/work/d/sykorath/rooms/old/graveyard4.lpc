// part of the graveyard
// made by magictcs - 2 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

string closed;
int warrior;
int moved;

//********
// go down
//********
int go_down() {
  if (!moved) return 0;
  write("You enter the small cave.\n");
  TP->move(SYKORATH("gravecave"),M_GO,"leaves down");
  return ME_OK;
}

//***************
// move tombstone
//***************
int move(string str) {
  notify_fail("Move what?\n");
  if (!str) return 0;
  if (member(({"plate","plate of grave","plate of the grave","heavy plate"}),
    str)!=-1) {
    if (moved) {
      write("You move the plate back.\n");
      show(NAME+" moves the plate.\n");
      moved=0;
    } else {
      write("You move the plate into another position.\n"
            "There is a way down under the plate.\n");
      show(NAME+" moves the plate.\n");
      moved=1;
    }
    return 1;
  }
  return 0;
}

//**************
// enter grave..
//**************
int enter(string str) {
  notify_fail("Enter where?\n");
  if (!str) return 0;
  if (member(({"grave","graves"}),str)!=-1) {
    if (closed=="open") {
      write("Better do never enter a open grave! The gravedigger may come "
        "and closes the grave!\n");
      return 1;
    } else {
      write("How do you want to enter a closed grave?\n");
      return 1;
    }
  }
  return 0;
}

//*************
// open grave..
//*************
int open(string str) {
  notify_fail("Open what?\n");
  if (!str) return 0;
  if (member(({"grave","graves"}),str)!=-1) {
    write("Better do never open a closed grave!\n");
    return 1;
  }
  return 0;
}

//***********
// close grave
//************
int close(string str) {
  notify_fail("Close what?\n");
  if (!str) return 0;
  if (member(({"grave","graves"}),str)!=-1) {
    if (closed=="open") {
      if (present("shovel",TP)) {
        write("You close the grave with your shovel.\n");
        show(NAME+" closes a grave.\n");
        TP->SetExplored();
        closed="closed";
        return 1;
      } else {
        write("You need a shovel to close this grave.\n");
        return 1;
      }
    } else {
      write("There is no open grave here!\n");
      return 1;
    }
  }
  return 0;
}

//****
// dig
//****
int dig(string str) {
  object obj;
  notify_fail("Dig where?\n");
  if (!str) return 0;
  if (member(({"grave","graves","at grave","at graves","on grave",
    "on graves"}),str)!=-1) {
    if (!present("pickaxe",TP)) {
      write("You need a pickaxe to dig here.\n");
      return 1;
    }
    write("You use your pickaxe to dig at a grave.\n");
    show(NAME+" digs at a grave.\n");
    if (warrior) {
      obj=clone_object(NPC("skeleton"));
      if (obj) {
        write("If you dig - a skeleton warrior appears out of the grave.\n");
        obj->move(TO,M_SILENT);
      }
      warrior=0;
    }
    return 1;
  }
  return 0;
}

//***************
// detailhandling
//***************
string lookgraves() {
  string ret;
  ret="The graves around you look old, except the one with the brandnew\n"
    "tombstone on it.\n";
  if (closed=="open") ret+="One grave is open.\n";
  return ret;
}

string lookopengrave() {
  if (closed!="open") return 0;
  return "You can close the grave.\n";
}

string lookwaydown() {
  if (!moved) return 0;
  return "You see a small cave there.\n";
}

string lookcave() {
  if (!moved) return 0;
  return "You can enter the small cave by going down.\n";
}

//*******
// create
//*******
create() {
  ::create();
  closed="open";
  warrior=1;
  moved=0;
  SetIntShort("South on a graveyard.\n");
  SetIntLong(
    "You are standing on an old graveyard. Some tombstones are standing\n"
    "around you. The graveyard is surrounded by a small wall.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"old graveyard","old yard","graveyard","yard"}),#'IntLong);
  AddDetail(({"small wall","wall","rotten wall","small rotten wall"}),
    "The wall is nearly rotten, but still around one metres huge.\n");
  AddDetail(({"grave","graves"}),#'lookgraves);
  AddDetail("open grave",#'lookopengrave);
  AddDetail(({"some tombstones","tombstones"}),
    "The tombstones are weathered. But one of them looks brandnew.\n");
  AddDetail(({"tombstone","one tombstone","brandnew tombstone"}),
    "This tombstone wasn't here for the last centuries. It is new. There is\n"
    "a small crack between the tombstone and the plate of a grave.\n");
  AddDetail(({"crack","small crack"}),
    "You examine the crack - looks that the plate is moveable.\n");
  AddDetail(({"plate","plate of grave","plate of the grave","heavy plate"}),
    "A stony plate, made of red marble. It is a heavy plate.\n");
  AddDetail(({"red marble","marble"}),
    "Red marble is a very expensive material. It is used for building houses\n"
    "normally, but sometimes someone uses it for making tombstones.\n");
  AddDetail(({"way down","down"}),#'lookwaydown);
  AddDetail(({"cave","small cave"}),#'lookcave);

  /* command */
  AddRoomCmd("move",#'move);
  AddRoomCmd("open",#'open);
  AddRoomCmd("close",#'close);
  AddRoomCmd("dig",#'dig);
  AddRoomCmd("enter",#'enter);

  /* exits */
  AddExit("northeast","./graveyard3");
  AddExit("north","./graveyard1");
  AddExit("down",#'go_down);
  HideExit("down",1);
}

// open the grave if it is closed :)
reset() {
  ::reset();
  if (closed=="closed") {
    tell_room(TO,"A gravedigger comes along and digs at a grave.\n");
    closed="open";
  }
  warrior=1;
  moved=0;
}

