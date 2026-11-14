// made by magictcs - 1 jun 97
// part of a new quest - the "eatcorpse"

// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

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

create() {
  ::create();
  SetIntShort("A small path");
  SetIntLong(
    "You are on a small path in the city. The way ends directly right before\n"
    "a huge townwall.\n"
    "There's a big stone table here.\n"
    "Only one way leads back to the mainplaza.\n");
  SetBright(0);
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);
  
  /* details */
  AddDetail(({"path","small path"}),#'IntLong);
  AddDetail("mainplaza",
    "It is more to the southeast.\n");
  AddDetail("back","You can go back by going east.\n");
  AddDetail(({"townwall","huge townwall"}),
    "You cannot enter it here and it is too smooth too climb it.\n");
  AddDetail(({"way","way back"}),
    "One way leads in and only one way leads back.\n");
  AddDetail(({"table","big table","big stone table","stone table"}),
    "You see some scratches and marks on the table.\n");
  AddDetail(({"scratches","marks","some scratches","some marks",
    "scratches and marks","some scratches and marks"}),
    "Maybe you can try to read the scratches and marks?\n");
  AddReadMsg(({"scratches","marks","some scratches","some marks",
    "scratches and marks","some scratches and marks"}),#'readscratches);
  AddReadMsg(({"table","big table","big stone table","stone table"}),
    "Try to read the marks.\n");
  SetIntSmell("A fouly smell reaches your nose.\n");
  SetIntNoise("You hear a strange noise made by some kind of living.\n");

  /* exits */
  AddExit("east","./mainroadnw");
}

