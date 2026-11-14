// part of the graveyard
// made by magictcs - 2 jul 97

// TODO: dig? open? close?
// add shadow warrior? skeleton warriors?
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

int warrior;

//*****
// open
//*****
int open(string str) {
  notify_fail("Open what?\n");
  if (!str) return 0;
  if (member(({"grave","graves"}),str)!=-1) {
    write("You can't open the graves with your bare hands. But maybe you "
      "can dig there?\n");
    show(NAME+" tries to open a grave.\n");
    return 1;
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

//******
// close
//******
int close(string str) {
  notify_fail("Close what?\n");
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  warrior=1;
  SetIntShort("North on a graveyard.\n");
  SetIntLong(
    "You are north of the entrance on a graveyard. You see some graves with\n"
    "their tombstones here.\n"
    "The graveyard is surrounded by a small wall.\n"
    "The exit is somewhere to the southwest.\n" );
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"old graveyard","old yard","graveyard","yard"}),#'IntLong);
  AddDetail(({"small wall","wall","rotten wall","small rotten wall"}),
    "The wall is nearly rotten, but still around one metres huge.\n");
  AddDetail("entrance","It is the place where you stand actually.\n");
  AddDetail("exit",
    "You can see the entrance of the graveyard to the south.\n");
  AddDetail(({"grave","graves"}),
    "The graves are all closed. \n");
  AddDetail("tombstone",
    "Each tombstone has an engraving on it. Some of them are readable, but\n"
    "some not.\n");
  AddDetail("tombstones","Each grave has it's own tombstone.\n");
  AddReadMsg(({"tombstone","tombstones","engraving on tombstones",
    "engraving on tombstone","engraving","engravings"}),
    "You go around and read some of the engravings:\n"
    "   -> To my beloved Johnny, your Anne <-\n"
    "   ...This is the last resting-place of Friederich!...\n"
    "and so on.\n");

  /* commands */
  AddRoomCmd("open",#'open);
  AddRoomCmd("close",#'close);
  AddRoomCmd("dig",#'dig);

  /* exits */
  AddExit("south","./graveyard1");
  AddExit("southeast","./graveyard3");
}

reset() {
  ::reset();
  warrior=1;
}

