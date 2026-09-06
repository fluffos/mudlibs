// made by magictcs - 10 aug 97
// the master room for the beaches, some things are handled by the VMASTER!

// TODO: add details for ground and ceiling

#include "sea.h"

inherit BASEROOM;

create() {
  ::create();
  Set(P_VMASTER,BEACHMASTER);
  SetIntShort("On a beach");
  SetIntLong("On a beach.\n");     // overriden by VMASTER
  SetIndoors(1);                            // we are in a grotto !

  /* some standard details for all beaches */
  AddDetail("beach",#'IntLong);
  AddVItem( ([
    P_IDS:  ({"sea"}),
    P_ADS:  ({"large"}),
    P_LONG: "It is a large sea to the west. The sea has black water in it.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({"west"}),
    P_LONG: "You sea a sea there. But the sea has not normal water in it! "
            "The exit of this large grotto must be somewhere in this sea.\n"
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

  /* exits are set by VMASTER! */
  // Noway-Msg is only used if there is no such exit!
  AddNowayMsg("west","You bump against a huge wall. Ouch that hurts.\n");
  AddNowayMsg("east","You bump against a huge wall. Ouch that hurts.\n");
  AddNowayMsg("north","You bump against a huge wall. Ouch that hurts.\n");
  AddNowayMsg("south","You bump against a huge wall. Ouch that hurts.\n");
}

GetExits() {
  return "";
}

