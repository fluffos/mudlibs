/*
 * example 1 for getable vitems
 * Magictcs - 12 march 98
 *
 * demonstrate how to use the new property for vitems to allow to get them
 */

/*
  How to use it:
  simplest version:

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    PV_ITEM_LOCATION: "path_for_file_to_clone",
  ]) );

  it is possible to cascade the vitems (like the knife in our example!):
  get knife from table
  vitem#1 = table
  vitem#2 = knife (cascaded to table and this item is get-able)

  the simplest form allows to get one item during one reset phase
  the next try is blocked by the get/take function
  (it can annoy a player that they can see the knife on the table, after
  they got it and they can't get it a second time!)
  how to prevent this?! -> see example: get2.c
*/ 

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>

inherit "/std/room";

//*******
// create
//*******
varargs void create() {
  string v_table;
  ::create();
  SetIntShort("The main plaza");
  SetIntLong("Example room1:\n"
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
    P_LONG: "It's an old table. But a knife is lying on it.\n"]) );
  AddVItem( ([
    P_IDS:  ({"knife"}),
    PV_ITEM_LOCATION: "/std/weapon",         // file to clone
    P_LONG: "A simple knife.\n"]),v_table);

  /* Exits */
  AddExit("east","./get2");
}

