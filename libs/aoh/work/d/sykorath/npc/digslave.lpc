// a slave who is digging new tunnels
// made by magictcs - 4 aug 1997
// the slave will be informed about all incoming players
// if one player arrives, the slave will start to dig a new tunnel north
// but if a new player arrives, it will take another two minutes to
// finish this work

#include <properties.h>
#include <sykorath.h>

inherit "/std/npc";

//******************
// notify_new_player
//******************
// called by the room, to notify a new player
void notify_new_player() {
  while (remove_call_out("open_exit") != -1);
  call_out("open_exit",120);       // start a call_out
}

//***************************
// call open_exit in the room
//***************************
void open_exit() {
  object room;
  room=environment();
  if (room) room->open_exit();
  // if the slave is moved to another room, nothing is happened! because
  // not existing functions return 0 !!
}

//****************************
// a 'nearly' normal create :)
//****************************
create() {
  if (::create()) return;
  SetRace("human");
  SetLevel(5);
  SetName("Slave");
  SetShort("a slave");
  SetLong(
    "A slave who is digging new tunnels into the rock!\n");
  AddId(({"slave","_dig_slave_"}));
  SetAds(({"skeleton"}));
  SetAggressive(0);
  SetGender(GENDER_MALE);

  InitChats(5,({
    "The slave digs very hard into the rock.\n",
    "The slave hmms.\n",
    "The slave says: A very hard rock here!\n",
    "The slave dries his sweat.\n",
    "You hear a loud 'Biiiing' as the slave digs with his shovel.\n"}));

  AddItem("/std/weapon",REFRESH_REMOVE,#'wieldme, ({
    ([ P_STANDARD: ({WT_CLUB,3,PSIZE_GENERIC}) ]),
    ([ P_SHORT: "a shovel",
       P_LONG:
       "This is steel shovel, mainly used for digging.\n",
       P_IDS: ({"shovel"}),
       P_ADS: ({"steel"}),
       P_WEIGHT: 3000,
       P_VALUE: 30, ]) }) );
}

