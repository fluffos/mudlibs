// made by magictcs - 10 aug 97
// the master room for the sea, some things are handled by the VMASTER!

// TODO: add details for ground and ceiling

#include <moving.h>
#include "sea.h"

inherit BASEROOM;

string down;

//******************
// property handling
//******************
string SetDown(string d) { down=d; return down; }
string QueryDown() { return down; }

//**************
// detail beach?
//**************
string lookbeach() {
  if (strstr(((QueryExits()["east"])||""),"beach")!=-1)
    return
    "There is a beach to the east.";
  return 0;
}

//*********************
// dive, if prop is set
//*********************
int dive(string str) {
  if (!down) return 0;
  if (str) { notify_fail("Use a simple 'dive'.\n"); return 0; }
  write("You dive into the black water.\n");
  TP->move(down,M_TELEPORT,({"dives into the black water"}));
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  down=0;
  Set(P_VMASTER,BEACHMASTER);
  SetIntShort("On a large sea");
  SetIntLong("Lost on a large sea.\n");     // overriden by VMASTER !?!?
  SetIndoors(1);                            // we are in a grotto !

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
  AddVItem( ([
    P_IDS:  ({ "beach" }),
    P_LONG: #'lookbeach
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

// remove the dropped item
void remove_item(object o) {
  if (o) {
    tell_room(TO,CAP(o->QueryShort()+
      " is too heavy and sinks to the ground.\n"));
    o->remove();
  }
}

// check drop items, if weight(item)>400 and item!=living
// --> sink to the ground
// but if the item consists of wood, don't sink!
void notify_enter(object oldenv,int method,mixed extra) {
  string *ids,*ads;
  ::notify_enter(oldenv,method,extra);
  if (PO->QueryIsLiving()) return;               // is a living
  ids=PO->QueryIds()||({""});
  ads=PO->QueryAds()||({""});
  if (member(ids,"wood")!=-1) return;            // is wood
  if (member(ads,"wooden")!=-1) return;          // is wood
  if (member(ads,"wood")!=-1) return;            // is wood
  if (PO->QueryWeight()<=400) return;            // light item
  call_out("remove_item",1,PO);
}
