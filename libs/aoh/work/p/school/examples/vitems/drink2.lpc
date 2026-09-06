/*
 * example 2 for drink-able vitems
 * Magictcs - 15 march 98
 *
 * demonstrate how to use the new property for vitems to allow to drink them
 * we want to limit the drinks!
 */

/*
  How to use it:
  simplest version:

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    P_DRINK: ([ drink-mapping ]) ,
    P_AMOUNT: amount,
  ]) );

  or

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    P_DRINK: #'closure_to_clone_me_a_drink_to_drink ,
    P_AMOUNT: amount,
  ]) );

  NOTE: as long as our drinks don't support properties - only the second
        version is correct!!!! ---> see examples

  it is possible to cascade the vitems (like the water in our example!):
  drink water from well
  vitem#1 = well
  vitem#2 = water (cascaded to well) 

*/ 

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>

inherit "/std/room";

// two vitem-ids:
string v_well;
string v_water;

//********************************
// clone our water object to drink
//********************************
object clone_water() {
  object ob;
  ob=clone_object("/std/food");        // use food - because no vessel!!!
  if (ob) {
    ob->SetShort("some water");        // for the failure messages needed!
    ob->SetFoodKind("drink");          // it is a drink
    ob->SetFoodMsgs(({
      "You drink some water from the well.\n",
      "@@Pl_Name@@ drinks some water from the well.\n" }));
    ob->SetFoodSoak(10);               // soaks good *grins*
    ob->SetHeal(0);                    // but no healing effect!
    // we can add alcohol as well as any other possible setting!
    return ob;                         // the obj will be consumed in future
  }
  return 0;
}

//******************************
// look at the water of the well
//******************************
string look_water_of_well() {
  if (VQuery(v_water,P_AMOUNT))
    return
    "Some clear water, you can drink it.\n";
  return "The well is dried out.\n";
}

//*****************
// look at the well
//*****************
string look_well() {
  if (VQuery(v_water,P_AMOUNT))
    return "It's an old well. You see some water.\n";
  return "It's an old dry well. No water is left there!\n";
}

//*******
// create
//*******
varargs void create() {
  ::create();
  SetIntShort("Example room 1");
  SetIntLong("Example room1:\n"
    "Try to look at the well and the water of it.\n"
    "Then try to drink the water from the well.\n"
    "(You can drink 5 times)\n"
    "A well is here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  v_well=AddVItem( ([
    P_IDS:  ({"well"}),
    P_ADS:  ({"old"}),
    P_PREPS: ({"of","from"}),
    P_LONG: #'look_well /*'*/ ]) );
  v_water=AddVItem( ([
    P_IDS:  ({"water"}),
    P_DRINK: #'clone_water, /*'*/ // can be a mapping too!
    P_AMOUNT: 5,                  // you can drink 5 times here, then the
                                  // well will dry out!
    P_LONG: #'look_water_of_well /*'*/ ]),v_well);

  /* Exits */
  AddExit("west","./drink1");
}

