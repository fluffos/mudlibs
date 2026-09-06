// part of the graveyard
// made by magictcs - 2 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

int whip;

//*****
// pull
//*****
int pull(string str) {
  string *exp;
  object obj;
  notify_fail("Pull what out of where?\n");
  if (!str) return 0;
  exp=explode(str," out of ");
  if (sizeof(exp)!=2) return 0;
  if (member(({"brick","special brick"}),exp[0])==-1) return 0;
  if (member(({"wall","small wall","rotten wall","small rotten wall"}),
    exp[0])==-1) {
    write("You pull the brick out of the wall.\n");
    show(NAME+" works with the wall.\n");
    if (whip) {
      write("Behind the prick you found a long whip.\n");
      obj=clone_object(WEAPON("lwhip"));
      TP->Take(obj,PUTGET_FULL);
      write("You put the brick back into the wall.\n");
      whip--;
    } else {
      write("But you found nothing behind the brick. You put it back into "
        "the wall.\n");
    }
    return 1;
  }
  notify_fail("Pull brick out of where?\n");
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  whip=1;
  SetIntShort("On a graveyard.\n");
  SetIntLong(
    "You are standing on an old graveyard. To the east is a small chapel and\n"
    "the entrance is to the west.\n"
    "The graveyard is surrounded by a small wall.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"old graveyard","old yard","graveyard","yard"}),#'IntLong);
  AddDetail(({"small wall","wall","rotten wall","small rotten wall"}),
    "The wall is nearly rotten, but still around one metres huge.\n"
    "There is a special brick in this wall.\n");
  AddDetail(({"brick","special brick","brick of wall","special brick of wall",
    "brick of small wall","special brick of small wall"}),
    "Maybe you can pull it out?\n");
  AddDetail("exit","You can leave the graveyard by going west.\n");
  AddDetail(({"grave","graves"}),
    "This is the place where the founders of the city are buried. Let they\n"
    "rest in peace!\n");

  /* commands */
  AddRoomCmd("pull",#'pull);

  /* exits */
  AddExit("west","./graveyard1");
  AddExit("northwest","./graveyard2");
  AddExit("east","./gravechapel");
  AddExit("southwest","./graveyard4");
}

// special reset
reset() {
  ::reset();
  whip=1;
}

