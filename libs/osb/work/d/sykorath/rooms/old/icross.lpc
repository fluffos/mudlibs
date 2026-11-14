// part of the town
// made by magictcs - 5 jun 97
// TODO: add more details
// TODO: change the search function :)
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//*****
// pray
//*****
int pray(string str) {
  write(
    "You want to pray to the old evil god called 'Xarxos', but there is only\n"
    "a ruin left here. you can't pray here.\n");
  show(NAME+" wants to pray, but fails.\n");
  return 1;
}

//*************
// search ruins
//*************
int search(string str) {
  string norm;
  notify_fail("You find nothing useful.\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (member(({"ruins","some ruins","temple","stones","old stones","place"}),
    norm)!=-1) {
    write("You search "+norm+", but find nothing useful.\n");
    show(NAME+" searches the "+norm+".\n");
    return 1;
  }
  return 0;
}

//******
// touch
//******
// maybe transfer the HP of player to an evil god Xarxos and if he got enough
// HP - he will appear???
int touch(string str) {
  string norm;
  notify_fail("Touch what?\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (member(({"cross","huge cross"}),norm)!=-1) {
    write("You touch the cross. You feel that the cross sucks your health.\n");
    show(NAME+" touches the cross.\n");
    TP->ReduceHP(5,5);       // players cannot die here! 5 HP left ever!
    return 1;
  }
  if (member(({"stone","stones","old stone","old stones","black stone",
    "black stones"}),norm)!=-1) {
    write(
    "You are going to touch the stones. Your finger comes near the stones.\n"
    "Some rays of a dark magic surround the stones. You decide better not\n"
    "touch them.\n");
    show(NAME+" wants to touch the stones.\n");
    return 1;
  }
  return 0;
}

//*************
// feel command
//*************
int feel(string str) {
  write("You have a very bad feeling here.\n");
  return 1;
}

//*****************
// get cross,stones
//*****************
int do_get(string str) {
  string norm;
  if (!str) return 0;
  norm=norm_id(str);
  if (present(norm)) return 0;        // for dropped items
  if (member(({"stone","stones","old stone","old stones","black stone",
    "black stones"}),norm)!=-1) {
    write("The stones emit a dark magic, you don't want to touch them!\n");
    show(NAME+" tries to get some stones. but fails.\n");
    return 1;
  }
  if (member(({"cross","huge cross"}),norm)!=-1) {
    write("How do you want to carry a cross of 5 metres height?\n");
    show(NAME+" tries to get "+str+", but fails.\n");
    return 1;
  }
  return 0;
}

void create() {
  ::create();
  SetIntShort("Near a huge cross");
  SetIntLong(
    "In a former time, this place belongs to the temple of 'Xarxos' but now\n"
    "there are only some ruins left here, except the huge cross standing\n"
    "here.\n"
    "You have a very uneasy feeling.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* detail */
  AddDetail("place",
    "In a former times it was a part of the temple of 'Xarxos'.\n");
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
  AddDetail(({"cross","huge cross"}),
    "it must be a wonder - the cross has no marks, it looks brandnew, but\n"
    "the other things lying around are older than thousand years.\n"
    "You can understand this, the cross has to be as old as the other things\n"
    "here. You have a feeling of touching the cross.\n");

  /* commands */
  AddRoomCmd("pray","pray");
  AddRoomCmd("search","search");
  AddRoomCmd("touch","touch");
  AddRoomCmd("get","do_get");
  AddRoomCmd("take","do_get");
  AddRoomCmd("feel",#'feel);

  /* exits */
  AddExit("northwest","./itemple");
}

