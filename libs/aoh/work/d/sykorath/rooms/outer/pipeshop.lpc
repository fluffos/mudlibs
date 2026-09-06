//
// pipeshop
// made by Magictcs
// sells only shoes and boots
//
// initial version - 17 sep 98

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

// check if the trading object is of type pipe or weed
int CheckTrade(object ob) {
  if (ob->id("pipe")) return 1;
  if (ob->id("weed"))  return 1;
  return 0;                          // discard all others
}

create() {
  ::create();
  SetIntShort("Pipeshop");
  SetIntLong(
    "You entered the workroom of the best pipemaker of the city. "
    "Ordinal and special pipes are sold here - made by Fluffy the "
    "pipemaker. "
    "To the west you see some shelves behind the counter. A sign hangs on "
    "the next wall. "
    "Sweet smoke itches in your nose. "
    "To the south you see a counter where Fluffy is selling the pipes. "
    "\n"
  );

  // add smell
  SetIntSmell("There is a smell of tobacco weed around.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({38,74,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("outer");

  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);               // noone should enter the store
  RemoveDustbin();              // no dustbin in shoemaker shop

  /* shopkeeper */
  SetShopkeeper(NPC("fluffy"));

  // details:
  // workroom,counter,workbench,different tool,

  AddVItem( ([
    P_IDS:  ({"workroom"}),
    P_LONG: "It's the workroom of Fluffy, thepipemaker.\n"]) );
  AddVItem( ([
    P_IDS:  ({"shelves","shelf"}),
    P_ADS:  ({"wooden","some"}),
    P_LONG: "Some wooden shelves are behind the counter. You see different "
            "types of pipes and pipe weed in them.\n"]) );
  AddVItem( ([
    P_IDS:  ({"pipe","pipes"}),
    P_LONG: "One pipe looks like a water pipe, another like a pipe for "
            "giants, one seems fit the gnomish sizes and so on. But they "
            "differ in the type of the material they made of too. "
            "Some are made of wood, some of steel, some of horns.\n"]) );
  AddVItem( ([
    P_IDS:  ({"weed"}),
    P_ADS:  ({"pipe"}),
    P_LONG: "Different type of pipe weed is lying in the shelves.\n" ]) );
  RemoveVItem(GetVItem("counter",2));
  AddVItem( ([
    P_IDS:  ({"counter"}),
    P_ADS:  ({"wooden"}),
    P_LONG: "The counter is made of wood. It stands between you and the "
              "shelves.\n"]) );
  AddVItem( ([
    P_IDS:  ({"wall"}),
    P_ADS:  "next",
    P_LONG: "A sign is attached there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"pipeshop"}),
    P_LONG: "You are standing in it.\n"]) );
  AddVItem( ([
    P_IDS:  ({"city","sykorath"}),
    P_ADS:  ({"city"}),
    P_LONG: "The pipeshop is part of the city sykorath too.\n"]) );


  // Exits:
  AddExit("northeast","./orcstreet6");
  HideExit("store",HIDE_ALWAYS);

  // add some pipe weed, some ordinary pipes, water pipes,large and small
  // ones...
  // herbpipes...
  AddArticle("/std/thing",REFRESH_REMOVE,2, ([
    P_SHORT:      "pipe weed",
    P_LONG:       "Best tobacco weed useful for any pipe.\n",
    P_IDS:        ({"weed"}),
    P_ADS:        ({"pipe"}),
    P_WEIGHT:     20,
    P_VALUE:      300
    ]) );
}

