/*
 * part of the graveyard of the outer city
 *
 * introduced:
 * Magictcs 02 jul 97 - first version
 *
 * updated:
 * Magictcs - 17 feb 98 - remade, added skills, fixed commands
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

int warrior;

//*****
// open
//*****
int open(string str) {
  notify_fail("Open what?\n");
  if (!str) return 0;
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|some|[ ])*(grave|graves)$"))==3) {
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
// TODO: add check if pickaxe is wielded:
//       if ((TP->QueryWeapons()[0])->id("pickaxe")) { ... }
// pickaxe has to be two handed to use this check (if it is wielded, no other
// weapon should be wieldable..)
int dig(string str) {
  object obj;
  notify_fail("Dig where?\n");
  if (!str) return 0;
  if (sizeof(regexplode(norm_id(str),
    "^(the|a|an|some|at|on|[ ])*(grave|graves)$"))==3) {
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

//**********
// searching
//**********
OnSucceedSearchingWall() {
  write("You search the wall, but you only found some dirt.\n");
  show(NAME+" searches the wall.\n");
  return 1;
}
OnFailSearchingWall() {
  write("You search the wall, but you found nothing.\n");
  show(NAME+" searches the wall.\n");
  return 1;
}
OnSucceedSearchingTombstone() {
  write("You search the tombstone and found an engraving there.\n");
  show(NAME+" searches the tombstones.\n");
  return 1;
}
OnFailSearchingTombStone() {
  write("You search the tombstone, but found nothing of interest.\n");
  show(NAME+" searches the tombstones.\n");
  return 1;
}
OnSucceedSearchingGrave() {
  write("You search the grave and found some heaps of soil. Looks like that "
        "the earth was moved some time ago.\n");
  show(NAME+" searches the grave.\n");
  return 1;
}
OnFailSearchingGrave() {
  write("You search the grave, but found nothing.\n");
  show(NAME+" searches the grave.\n");
  return 1;
}

//****************
// read tombstones
//****************
string read_tombstones() {
  return
    "You go around and read some of the engravings:\n"
    "   -> To my beloved Johnny, your Anne <-\n"
    "   ...This is the last resting-place of Friederich!...\n"
    "and so on.\n";
}

//*******
// create
//*******
create() {
  string tombstone,wall,grave;
  ::create();
  warrior=1;
  SetIntShort("North on a graveyard");
  SetIntLong(
    "You are north of the entrance on a graveyard. You see some graves "
    "with their tombstones here. The graveyard is surrounded by a small "
    "wall. The exit is somewhere to the southwest.\n" );
  SetIndoors(0);
  SetCoordinates( ({ ({760,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  AddNowayMsg(({"north","northwest","west","southwest"}),
    "You bump against the small wall.\n");

  /* details */
  AddVItem( ([
    P_IDS:  ({"graveyard","yard"}),
    P_ADS:  ({"old"}),
    P_LONG: #'IntLong ]) );
  wall = AddVItem( ([
    P_IDS:  ({"wall"}),
    P_ADS:  ({"small","rotten"}),
    P_LONG: "The wall is nearly rotten, but still around one metres "
            "huge.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"entrance"}),
    P_LONG: "It is more to the south.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"exit"}),
    P_LONG: "You can see the entrance of the graveyard to the "
            "south.\n" ]) );
  grave = AddVItem( ([
    P_IDS:  ({"grave","graves"}),
    P_ADS:  ({"closed","some"}),
    P_LONG: "The graves are all closed.\n" ]) );
  tombstone = AddVItem( ([
    P_IDS:  ({"tombstone","tombstones"}),
    P_LONG: "Each tombstone has an engraving on it. Some of them are "
            "readable, but some not.\n",
    P_READ_MSG: #'read_tombstones,
    P_PREPS: ({"on","of"}) ]) );
  // one time with preps, one time without them!
  AddVItem( ([
    P_IDS:  ({"engraving","engravings"}),
    P_LONG: "Nearly each tombstone has it's own engraving. Most of them "
            "are still readable!\n",
    P_READ_MSG: #'read_tombstones,
    P_PREP_REQUIRED : 0 ]), tombstone );
  AddVItem( ([
    P_IDS:  ({"engraving","engravings"}),
    P_LONG: "Nearly each tombstone has it's own engraving. Most of them "
            "are still readable!\n",
    P_READ_MSG: #'read_tombstones ]) );


  /* commands */
  AddRoomCmd("open",#'open);
  AddRoomCmd("close",#'close);
  AddRoomCmd("dig",#'dig);
  AddSkill(SK_SEARCH,"wall",50,wall);
  AddSkill(SK_SEARCH,"tombstone",20,tombstone);
  AddSkill(SK_SEARCH,"grave",50,grave);

  /* exits */
  AddExit("northeast","./graveyard7");
  AddExit("south",    "./graveyard1");
  AddExit("southeast","./graveyard3");
  AddExit("east",     "./graveyard5");

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^ then remove this message :)\n"
  );
}

//*********************
// special reset needed
//*********************
reset() {
  ::reset();
  warrior=1;
}

