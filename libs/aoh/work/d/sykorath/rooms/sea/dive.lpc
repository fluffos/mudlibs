// made by magictcs - 11 aug 97
// the master room for the underwater sea,
// some things are handled by the VMASTER!

// TODO: add details for ground and ceiling

#include <moving.h>
#include "sea.h"

inherit "/room/environ";

string down;
string up;

//******************
// property handling
//******************
string SetDown(string d) { down=d; return down; }
string QueryDown() { return down; }
string SetUp(string u) { up=u; return up; }
string QueryUp() { return up; }

//*********************
// dive, if prop is set
//*********************
int dive(string str) {
  if (!str) { notify_fail("Dive up or down?\n"); return 0; }
  if (str!="down" && str!="up") {
    notify_fail("Dive up or down?\n"); return 0; }
  if (str=="down") {
    if (!down) { notify_fail("You reached the ground already!\n");
                 return 0; }
    write("You dive deeper into the black water.\n");
    TP->move(down,M_TELEPORT,({"dives deeper into the black water"}));
    return 1;
  }
  write("You dive up.\n");
  TP->move(up,M_TELEPORT,({"dives up"}));
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  down=0;
  up=0;
  Set(P_VMASTER,BEACHMASTER);
  SetIntShort("Under the black water");
  SetIntLong("Under the black water.\n");     // overriden by VMASTER !?!?
  SetIndoors(1);                            // we are in a grotto !

  /* add special damage for under water */
  AddEnvironment(DT_NOAIR,80,"You cannot breath under water!\n");

  /* some standard details for all beaches */
  AddVItem( ([
    P_IDS:  ({"sea"}),
    P_ADS:  ({"large"}),
    P_LONG: #'IntLong
    ]) );
  AddVItem( ([
    P_IDS:  ({"water"}),
    P_ADS:  ({"black"}),
    P_LONG: "It is some sort of black water. Looks a little bit dangerous. "
            "But somewhere in this water must be the exit of this sea.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "wall","walls" }),
    P_ADS:  ({ "huge","black" }),
    P_LONG: "The wall belongs to this large grotto. It consists of black "
            "stone. There is no way through the stone and the stone is too "
            "slippery to climb.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "stone" }),
    P_ADS:  ({ "black" }),
    P_LONG: "Yeah black stone. You can't identify the stones, but it is a "
            "very hard stone!\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "grotto" }),
    P_ADS:  ({ "large" }),
    P_LONG: "The grotto is a very huge ones. The ceiling is around 150 metres "
            "above you. The grotto is built into some sort of black stone. "
            "You don't know if this is a natural or an articial grotto.\n"
    ]) );

  /* coammnds */
  AddRoomCmd("dive","dive");

  /* exits are set by VMASTER! */
  // Noway-Msg is only used if there is no such exit!
  AddNowayMsg("east","You bump against a huge wall. Ouch that hurts.\n");
  AddNowayMsg("north","You bump against a huge wall. Ouch that hurts.\n");
  AddNowayMsg("south","You bump against a huge wall. Ouch that hurts.\n");
  AddNowayMsg("west","You bump against a huge wall. Ouch that hurts.\n");
}

GetExits() {
  return "";
}

