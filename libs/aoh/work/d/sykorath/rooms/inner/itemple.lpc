/*
 * inner temple of cruel god
 * made by magictcs - 5 jun 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

// TODO: add a sacrifice command?
// TODO: add more details
// TODO: add special commands like "feel", search ruins, ...

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

inherit SY_STREET;

string vitem_staff;                 // VSet/VQuery handling !

//******************
// property handling
//******************
int QueryStaff()    { return VQuery(vitem_staff,P_AMOUNT); }
int SetStaff(int s) { VSet(vitem_staff,P_AMOUNT,s); return QueryStaff(); }

//***************
// kick player :)
//***************
void kick(object pl) {
  if (!pl) return;
  show_room(TO,
    "You see a dark shadow coming out of the earth. It forms a huge human. "
    "But you can't take a closer look at him, because his contours are not "
    "stable. The shadow runs to "+pl->QueryName()+" and kicks "+
    pl->QueryObjective()+" in the butt.\n"
    "The shadow growls and vanishes again.\n");
}

//*****
// pray
//*****
int pray(string str) {
  write(
    "You want to pray to the old evil god called 'Xarxos', but there is "
    "only a ruin left here. But you cry your prayer out to hell.\n");
  show(NAME+" sends "+B_POSS(TP)+" prayer to hell.\n");
  call_out("kick",1,TP);
  return 1;
}

//*************
// search ruins
//*************
int OnSucceedSearchingRuins() {
  write("You search the ruins and the stones, but find only bones of "
        "old fighters and mages.\n");
  if (VQuery(vitem_staff,P_AMOUNT))
    write("Oh stop , there seems to be something between the bones.\n");
    show(NAME+" searches the ruins and the stones.\n");
  return 1;
}

int OnSucceedSearchingBones() {
  if (VQuery(vitem_staff,P_AMOUNT))
    write("You find an old staff of an evil mage.\n");
  else
    return 0;
  show(NAME+" searches bones.\n");
  return 1;
}

//*****************
// get stones o.ae.
//*****************
object clone_staff(object pl) {
  object ob;
  ob=clone_object("/std/weapon");
  ob->SetProperties( ([ P_STANDARD: ({WT_STAFF,5,PSIZE_GENERIC}) ]) );
  ob->SetProperties(
    ([ P_SHORT:  "an old staff",
       P_LONG:   "An old staff, that belongs to an evil mage in former "
                 "times.\n",
       P_VALUE:  345,
       P_WEIGHT: 534,
       P_IDS:    ({"staff","weapon"}),
       P_ADS:    ({"old"})
    ]) );
  return ob;
}

//***************
// detailhandling
//***************
string lookmages() {
  if (VQuery(vitem_staff,P_AMOUNT)) return
    "The battle was ages ago. Only some bones of them and some of their\n"
    "equipment (like staffs..) are left.\n";
  return
  "The battle was ages ago. Only some bones of them are left.\n";
}

string lookstaff() {
  if (!VQuery(vitem_staff,P_AMOUNT)) return 0;
  return
  "It is an very old staff, looks like a staff of one of the evil mages.\n";
}

//*******
// create
//*******
void create() {
  string v_id;
  ::create();
  SetIntShort("The inner temple");
  SetIntLong(
    "In former time, this was the temple of 'Xarxos' but now - there "
    "are only some ruins left here. It looks like a great battlefield "
    "between the mights of god and hell. Many good fighters and mages "
    "(bright and dark ones) died here. You see stones covered with marks "
    "of the magic attacks. You have a very uneasy feeling.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({560,640,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  SetMap("inner");

  /* detail */
  AddVItem( ([
    P_IDS:  ({"temple","temple of xarxos","temple of Xarxos"}),
    P_ADS:  ({"inner"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"ruin","ruins","battlefield","great battlefield"}),
    P_LONG: "Only some ruins are left here. You see the old stones, "
            "covered with unnumbered marks of the fights between the "
            "good and evil mages.\n" ]) );
  v_id=AddVItem( ([
    P_IDS:  ({"stone","stones"}),
    P_ADS:  ({"old"}),
    P_NOGET:"The stones of the ruins are too heavy to get.\n",
    P_PREPS:({"on","at","of"}),
    P_LONG: "Old stones, now blackened by the cruel fight between "
            "the mages of the light and darkness. Many marks can be "
            "seen on the stones.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"mark","marks"}),
    P_ADS:  ({"unnumbered"}),
    P_READ_MSG: "They are marks of a cruel fight, not marks made "
            "for reading.\n",
    P_LONG: "You see many marks on the old stones. The fight has to be "
            "very cruel. It looks like that noone had won this fight.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"fighter","fighters"}),
    P_ADS:  ({"good"}),
    P_LONG: "The battle was ages ago. Only some bones are left.\n" ]) );
  // if next ids to ads+ids are splitted: 'look evil good mages' :((
  AddVItem( ([
    P_IDS:  ({"mage","mages","good mage","good mages","evil mage",
              "evil mages"}),
    P_LONG: #'lookmages ]) );
  AddVItem( ([
    P_IDS:  ({"bone","bones"}),
    P_NOGET:"They are nearly rotten and useless.\n",
    P_LONG: "You see the bones of fighters and mages.\n" ]) );
  vitem_staff=AddVItem( ([
    P_IDS:  ({"equipment","staff","staffs"}),
    P_AMOUNT:1,
    PV_ITEM_LOCATION: #'clone_staff,
    P_LONG: #'lookstaff ]) );

  /* commands */
  AddRoomCmd("pray","pray");
  AddSkill(SK_SEARCH,"ruin",25,({"ruins","ruin","stone","stones"}));
  AddSkill(SK_SEARCH,"bones",25,({"bone","bones"}));

  /* exits */
  AddExit("southeast","./icross");
  AddExit("north","./bank");

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

