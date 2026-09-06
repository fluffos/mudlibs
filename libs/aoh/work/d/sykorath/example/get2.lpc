/*
 * example 2 for getable vitems
 * Magictcs - 12 march 98
 */

/*
  How to use it:
  enhanced version:

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    PV_ITEM_LOCATION: "path_for_file_to_clone",
    P_AMOUNT: number_of_items_of_this_type_available,
  ]) );

  the item is the same like in example get1.c,but now we specify that there
  are just 2 knives lying on the table.
  if both are got, we wait for the next reset and can get two new knives

  The array for the property entry of PV_ITEM_LOCATION is needed, because we
  want to know the number of items available!

  we use a closure to evaluate the number of knives on the table to
  return the correct string!
*/

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

string vitem_knife;       // we should know what id our vitm have

// look at the knife on the table:
string look_knife() {
  switch (VQuery(vitem_knife,P_AMOUNT)) {
    case 2:               // two knives
    case 1:               // one knife
      return "A simple knife.\n";
    default: return 0;    // no knife left!
  }
}

// look at the table
string look_table() {
  switch (VQuery(vitem_knife,P_AMOUNT)) {
    case 2:
      return "It's an old table. Two knives are lying on it.\n";
    case 1:
      return "It's an old table. But a knife is lying on it.\n";
    default:
      return "It's an old table.\n";  // no knife left!
  }
}

//*******
// create
//*******
create() {
  string v_table;
  ::create();
  SetIntShort("Example2");
  SetIntLong("Example room2:\n"
    "Try to look at the table and the knife on it.\n"
    "Then get the table and/or the knife.\n"
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
    PV_ITEM_LOCATION: "/std/weapon",  // file to clone,two knives
    P_AMOUNT: 2,                      // 2 knives available
    P_LONG: #'look_knife ]),v_table);

  /* Exits */
  AddExit("east","./get3");
  AddExit("west","./get1");
}
