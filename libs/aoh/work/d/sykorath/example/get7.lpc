/*
 * example 7 for getable vitems
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
  but we want to have unlimited items!

  if you want to take the object, the closure is called and has to return
  the cloned object or 0 (if there was something wrong)
*/

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

// closure func to clone the vitem!
object clone_a_leaf() {
  object ob;
  ob=clone_object("/std/unit");       // we use unit for unlimited objects!
  if (ob) {                         // do we have a clone?
    ob->SetProperties( ([
      P_IDS: ({"leaf"}),
      P_PLURAL_IDS: ({"leaves"}),
      P_ADS: ({"brown"}),
      P_AMOUNT: 1,                  // a single leaf
      P_SHORT: "leaf",
      P_LONG: "A brown leaf.\n",
      P_PLURAL_SHORT: "leaves",
      P_PLURAL_LONG: "Many brown leaves.\n"      
      // set weight and so on....
      ]) );
    return ob;
  }
  return 0;                           // something was wrong - contact a wiz
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Example7");
  SetIntLong("Example room7:\n"
    "(Unlimited leaves are available)\n"
    "Leaves are all around you.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"leaf","leaves"}),
    PV_ITEM_LOCATION: #'clone_a_leaf,   // closure_to_clone_object
    P_MAX_AMOUNT: -1,                   // unlimited !!
    P_LONG: "Leaves are lying around.\n" ]));

  /* Exits */
  AddExit("west","./get6");
}
