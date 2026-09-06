/*
 * example 3 for getable vitems
 * Magictcs - 12 march 98
 */

/*
  How to use it:
  more enhanced version:

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    PV_ITEM_LOCATION: #'closure_to_clone_object,
  ]) );

  the item is the same like in example get1.c,
  but we use now a closure instead of the needed filename of the object to
  clone

  if you want to take the object, the closure is called and has to return
  the cloned object or 0 (if there was something wrong)
  You are now able to limit the number of items to get with this closure!

*/

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>

inherit "/std/room";

#define TP this_player()
#define TO this_object()

string vitem_knife;       // we should know what id our vitm have

// look functions are the same as in 'get2.c'

// look at the knife on the table:
string look_knife() {
  switch (VQuery(vitem_knife,P_AMOUNT)) {
    case 2:
    case 1:
      return "A simple knife.\n";
    default: return 0;
  }
}

// look at the table
string look_table() {
  switch (VQuery(vitem_knife,P_AMOUNT)) {
    case 2:
      return "It's an old table. Two knives are stuck on it.\n";
    case 1:
      return "It's an old table. But a knife is stuck on it.\n";
    default:
      return "It's an old table.\n";
  }
}

// closure func to clone the vitem!
object clone_a_knife() {
  object ob;
  if (present("axe",TP)) {            // has the player an axe?
    ob=clone_object("/std/weapon");   // yes he has -> clone the item
    if (ob) {                         // do we have a clone?
      write(
        "You use your axe to pick the wood around that knife to free it!\n");
      return ob;
    }
  }
  write ("You need a axe to do this!\n");   // send failure
  return 0;
}

//*******
// create
//*******
create() {
  string v_table;
  ::create();
  SetIntShort("Example3");
  SetIntLong("Example room3:\n"
    "Try to look at the table and the knife on it.\n"
    "Then get the table and/or the knife.\n"
    "(The torch is only get-able if you have a axe with you)\n"
    "A table is here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  v_table=AddVItem( ([
    P_IDS:  ({"table"}),
    P_ADS:  ({"old"}),
    P_PREPS: ({"on","from"}),
    P_LONG: #'look_table ]) );
  vitem_knife=AddVItem( ([
    P_IDS:  ({"knife"}),
    PV_ITEM_LOCATION: #'clone_a_knife,  // closure_to_clone_object
    P_AMOUNT: 2,                        // how many objects are available?
    P_LONG: #'look_knife ]),v_table);

  /* Exits */
  AddExit("east","./get4");
  AddExit("west","./get2");
}
