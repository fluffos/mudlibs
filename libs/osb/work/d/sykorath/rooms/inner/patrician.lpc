/*
 * part of inner city
 * burned down house of the old patrician
 *
 * NOTE: don't add any description for 'house' - it is handled by the
 *       object house itself!
 *
 * last changes:
 * [m] 21 jan 97 - first version
 */

// TODO: add object (inroom) for house
// TODO: stone dragon - which will come to life and burn down
//       the house, if the workers finished their work

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

// Message of the workers and the ongoing building of the room
string * build_msgs = ({
  "Some carpenters comes from the east with their tools to start "
      "building a new house.\n",

  "Some of the workers prepare the ground for the house to built.\n",

  "From the west comes some workers, drop their load for the house "
      "and then they leaving the place. The carpenters get the wood.\n",

  "One of the carpenters shouts: 'Heya' and they raise one of the wooden "
      "walls of the house.\n",

  "The workers fixed the wall with some nails.\n",

  "Another wall is raisen and fixed.\n",

  "And the next wall is raisen. Now the house looks like real house.\n",

  "Some carpenters work inside the house, sometimes you see some inside "
      "the new windows of the new built house.\n",

  "The house looks nearly finished.\n",

  "The carpenters finished their work. The house is rebuilt now.\n",

  "You see the carpenters resting a little bit. Then they take their tools "
      "and they are going to the west.\n"
});

int build_state;               // workers are working?

int timeout;                   // ==1 - no new house is allowed

//******************
// property handling
//******************
int QueryBuildState() { return build_state; }
int SetBuildState(int s) { return build_state=s; }
string *QueryBuildMsgs() { return build_msgs; }      // read only!

//**************
// special looks
//**************
string look_workers() {
  if (!build_state) return 0;
  // add special msgs, depending from the build_start variable?
  // the workers make a small pause? or similar....?
  return
  "Some carpenters, which are working hard to build the new house.\n";
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The house of the patrician");
  SetIntLong(
    "In former times there was a huge house of the patrician here. "
    "But this one is burned down in the evil war between the two main "
    "groups. Some very mighty mages casted their spells here!\n");

  SetIndoors(0);
  SetCoordinates( ({ ({660,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddDetail("town","You are standing inmids the town.\n");
  AddVItem( ([
    P_IDS:  ({"worker","workers","carpenter","carpenters"}),
    P_ADS:  ({"some"}),
    P_LONG: #'look_workers ]) );

  /* items */
  AddItem(OBJ("patrician_dragon"),REFRESH_NONE);
  AddItem(OBJ("patrician_house"),REFRESH_NONE);

  /* Exits */
  AddExit("west","./to_patrician");

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//*******************************************************************
// Workers work in this room, they rebuild the house of the patrician
//*******************************************************************

// detect entering of players
// we don't want to use heart_beat - it needs too much resources
// we start a call_out instead!
void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (!interactive(PO)) return;             // no interactive
  if (find_call_out("working")!=-1) return; // call out is running already
  if (timeout) return;                      // wait a little bit
  call_out("working",random(10)+5);         // start building
}

//************************
// show the working msgs
// notify the house itself
//************************
void working() {
  object house;
  house=present("__patrician_house__");
  if (build_state==sizeof(build_msgs)) {
    build_state=0;                           // reset the workers
    RemoveExtraEntry("workers",P_INT_LONG);  // remove them :)
    timeout=1;                               // forbid new house
    call_out("timeout_to_new_house",240);    // next house start after 4 mins
    return;
  }
  show_room(TO,build_msgs[build_state]);
  house=present("__patrician_house__");
  if (house) {
    house->SetBuildState(build_state);   // set the house
    if (build_state==(sizeof(build_msgs)-1))
      house->SetFinished(1);             // the house is finished
  }
  build_state++;
  SetExtraEntry("workers", P_INT_LONG,"Some carpenters are working here.\n");
  // maybe set the extra-entry as closure?!
  // SetExtraEntry(....,#'look_workers);
  call_out("working",random(10)+5);
}

// allow new house to built
void timeout_to_new_house() {
  timeout=0;
}

