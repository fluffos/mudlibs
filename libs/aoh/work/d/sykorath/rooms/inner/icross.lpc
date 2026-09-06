/*
 * part of the town 
 * made by magictcs - 5 jun 97
 *
 * last changes:
 * [m] 10 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>
#include <skills.h>

inherit SY_STREET;

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
int OnSucceedSearchingRuins(object who,int s,string what,
  string extra,mixed p) {
  write("You search "+what+" but found nothing useful.\n");
  show(NAME+" searches the "+what+".\n");
  return 1;
}

//******
// touch
//******
// TODO: maybe transfer the HP of player to an evil god Xarxos and 
// TODO: if he got enough HP - he will appear???
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

//*******
// create
//*******
void create() {
  ::create();
  SetIntShort("Near a huge cross");
  SetIntLong(
    "In a former time, this place belongs to the temple of 'Xarxos' but "
    "now there are only some ruins left here, except the huge cross "
    "standing here. You have a very uneasy feeling.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({580,660,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* detail */
  AddDetail("place",
    "In a former times it was a part of the temple of 'Xarxos'.\n");
  AddVItem( ([
    P_IDS:  ({"temple","temple of xarxos","temple of Xarxos"}),
    P_ADS:  ({"inner"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"ruin","ruins","battlefield"}),
    P_LONG: "Only some ruins are left here. You see the old stones, "
            "covered with unnumbered marks of the fights between the "
            "good and evil mages.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"stone","stones"}),
    P_ADS:  ({"old"}),
    P_NOGET:"The stones emit a dark magic, you don't want to touch them!\n",
    P_LONG: "Old stones, now blackened by the cruel fight between "
            "the mages of the light and darkness. Many marks can be "
            "seen on the stones.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"mark","marks"}),
    P_ADS:  ({"unnumbered"}),
    P_LONG: "You see many marks on the old stones. The fight has to "
            "be very cruel. It looks like that noone had won this "
            "fight.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"cross","huge cross"}),
    P_NOGET:"How do you want to carry a cross of 5 metres height?\n",
    P_LONG: "It must be a wonder - the cross has no marks, it looks "
            "brandnew, but the other things lying around are older "
            "than thousand years. You can understand this, the cross "
            "has to be as old as the other things here. You have a "
            "feeling of touching the cross.\n" ]) );

  /* commands */
  AddRoomCmd("pray","pray");
  AddSkill(SK_SEARCH,"ruins",75,({"ruins","some ruins","temple",
           "stones","old stones","place"}));
  AddRoomCmd("touch","touch");
  AddRoomCmd("feel",#'feel);

  /* exits */
  AddExit("northwest","./itemple");

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

