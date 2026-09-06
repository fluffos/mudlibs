// part of the town
// made by magictcs - 5 jun 97
// TODO: add more details
// TODO: add special commands like "feel", search ruins, ...
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

int staff;

//******************
// property handling
//******************
int QueryStaff()    { return staff; }
int SetStaff(int s) { staff=s; return staff; }

//***************
// kick player :)
//***************
void kick(object pl) {
  if (!pl) return;
  tell_room(TO,
    "You see a dark shadow coming out of the earth. It forms a huge human.\n"
    "But you can't take a closer look at him, because his contours are not\n"
    "stable. The shadow runs to "+pl->QueryName()+" and kicks "+
    pl->QueryObjective()+" in the butt.\n"
    "The shadow growls and vanishes again.\n");
}

//*****
// pray
//*****
int pray(string str) {
  write(
    "You want to pray to the old evil god called 'Xarxos', but there is only\n"
    "a ruin left here. But you cry your prayer out to hell.\n");
  show(NAME+" sends "+B_POSS(TP)+" prayer to hell.\n");
  call_out("kick",1,TP);
  return 1;
}

//*************
// search ruins
//*************
int search(string str) {
  string ret;
  if (!str) { notify_fail("You found nothing.\n"); return 0; }
  if (member(({"ruins","ruin","stone","stones"}),str)!=-1) {
    ret="You search the "+str+
        ", but find only bones of old fighters and mages.\n";
    if (staff)
      ret+="Oh stop , there seems to be something between the bones.\n";
    write(ret);
    show(NAME+" searches the "+str+".\n");
    return 1;
  }
  if (member(({"bone","bones"}),str)!=-1) {
    if (staff)
      ret="You find an old staff of an evil mage.\n";
    else ret="You found nothing.\n";
    write(ret);
    show(NAME+" searches the "+str+".\n");
    return 1;
  }
  return 0;
}

//*****************
// get stones o.ae.
//*****************
void clone_staff(object pl) {
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
  ob->move(TO,M_SILENT);
  pl->Take(ob,PUTGET_FULL);
}

int do_get(string str) {
  string norm;
  if (!str) return 0;
  norm=norm_id(str);
  if (present(norm)) return 0;         // for dropped items
  if (member(({"stone","stones"}),norm)!=-1) {
    write("The stones of the ruins are too heavy to get.\n");
    show(NAME+" tries to get some stones. but fails.\n");
    return 1;
  }
  if (member(({"staff","old staff",}),str)!=-1) {
    if (!staff) return 0;
    clone_staff(TP);
    staff--;
    return 1;
  }
  return 0;
}

//***************
// detailhandling
//***************
string lookmages() {
  if (staff) return
    "The battle was ages ago. Only some bones of them and some of their\n"
    "equipment (like staffs..) are left.\n";
  return
  "The battle was ages ago. Only some bones of them are left.\n";
}

string lookstaff() {
  if (!staff) return 0;
  return
  "It is an very old staff, looks like a staff of one of the evil mages.\n";
}

void create() {
  ::create();
  staff=1;
  SetIntShort("The inner temple");
  SetIntLong(
    "In former time, this was the temple of 'Xarxos' but now - there are\n"
    "only some ruins left here.\n"
    "It looks like a great battlefield between the mights of god and hell.\n"
    "Many good fighters and mages (bright and dark ones) died here.\n"
    "You see stones covered with marks of the magic attacks.\n"
    "You have a very uneasy feeling.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* detail */
  AddDetail(({"temple","inner temple","temple of xarxos","temple of Xarxos"}),
    #'IntLong);
  AddDetail(({"ruin","ruins","battlefield"}),
    "Only some ruins are left here. You see the old stones, covered with\n"
    "unnumbered marks of the fights between the good and evil mages.\n");
  AddDetail(({"stone","stones","old stone","old stones"}),
    "Old stones, now blackened by the cruel fight between the mages of the\n"
    "light and darkness.\n"
    "Many marks can be seen on the stones.\n");
  AddDetail(({"mark","marks","unnumbered marks",}),
    "You see many marks on the old stones. The fight has to be very cruel.\n"
    "It looks like that noone had won this fight.\n");
  AddDetail(({"fighter","fighters","good fighter","good fighters"}),
    "The battle was ages ago. Only some bones are left.\n");
  AddDetail(({"mage","mages","good mage","good mages","evil mage",
    "evil mages"}),#'lookmages);
  AddDetail(({"bone","bones"}),
    "You see the bones of fighters and mages.\n");
  AddDetail(({"equipment","staff","staffs"}),#'lookstaff);
  AddReadMsg(({"mark","marks","unnumbered marks",}),
    "They are marks of a cruel fight, not marks made for reading.\n");

  /* commands */
  AddRoomCmd("pray","pray");
  AddRoomCmd("search","search");
  AddRoomCmd("get","do_get");
  AddRoomCmd("take","do_get");

  /* exits */
  AddExit("southeast","./icross");
  AddExit("north","./mainroadsw");
}

reset() {
  ::reset();
  staff=1;
}
