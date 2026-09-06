/*
 * part of the eatcorpse quest
 * made by magictcs - 1 jun 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit SY_STREET;

// possibility for enhancements:
string readscratches() {
  if (!present("potion_of_giant_wisdom",this_player()))
  return
    "You try to read the scratches and marks, but it seems that they don't\n"
    "belong to any language you know.\n"
    "Trying to read them is only waste of time.\n"
    "You need much more wisdom to read the scratches.\n";
  // give one explorer point for finding the inscription
  TP->SetExplored();
  return
    "With the potion of giant wisdom you are manage to read the scratches:\n"
    "    Find a small puddle in this city. There is a secret way to\n"
    "    enter it. Please help me. I believe I'm not as strong as you?\n"
    "            signed: Josie\n";
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A small path");
  SetIntLong(
    "You are on a small path in the city. The way ends directly right "
    "before a huge townwall. There's a big stone table here. Only one "
    "way leads back to the mainplaza.\n");

  SetBright(0);
  SetIntSmell("A fouly smell reaches your nose.\n");
  SetIntNoise("You hear a strange noise made by some kind of living.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({540,580,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");
  
  /* details */
  AddVItem( ([
    P_IDS:  ({"path"}),
    P_ADS:  ({"small"}),
    P_LONG: #'IntLong ]) );
  AddDetail("mainplaza",
    "It is more to the southeast.\n");
  AddDetail("back","You can go back by going east.\n");
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"huge"}),
    P_LONG: "You cannot enter it here and it is too smooth too "
            "climb it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"way","way back"}),
    P_LONG: "One way leads in and only one way leads back.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"table"}),
    P_ADS:  ({"big","stone"}),
    P_LONG: "You see some scratches and marks on the table.\n",
    P_READ_MSG: "Try to read the marks.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"scratches","marks"}),
    P_ADS:  ({"some"}),
    P_LONG: "Maybe you can try to read the scratches and marks?\n",
    P_READ_MSG: #'readscratches ]) );

  /* exits */
  AddExit("east","./to_plate");

  Set(P_INT_WIZMSG,
    "%^RED%^add details, make recursive vitems!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

