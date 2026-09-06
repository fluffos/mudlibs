//
// part of south street
// initial version - magictcs - 13 sept 98
//

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

//vitems
string v_flowers;

object clone_flowers() {
  object f;
  if (VQuery(v_flowers,P_AMOUNT)>1) {   // amount == 1 --> don't clone,
                                        // but send special error message
    f = clone_object("/std/thing");
    f->SetShort("bunch of flowers");
    f->SetLong("A bunch of some beautiful flowers, the right present for "
               "a nice girl.\n");
    f->SetWeight(300);
    f->SetValue(25);
    f->SetIds(({"flower","flowers"}));
    return f;
  }
  notify_fail("Better leave some flowers left.\n",NOTIFY_NOT_VALID);
  return 0;
}

create() {
  string v_puddle;
  ::create();
  SetIntShort("On a small path");
  SetIntLong(
    "You stand on a small path. Between some beautiful flowers is a "
    "puddle filled wih dirty water.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({360,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetMap("outer");

  // details:
  v_puddle=AddVItem( ([
    P_IDS:  ({"puddle"}),
    P_PREPS: ({"of","from"}),
    P_LONG: "It's an puddle filled with dirty water.\n"]) );
  AddVItem( ([
    P_IDS:  ({"water"}),
    P_ADS:  ({"dirty"}),
    P_DRINK: ([P_SHORT:    "some water",
               P_FOOD_KIND: "drink",
               P_FOOD_MSGS: ({"You drink some water from the well.\n",
                      "@@Pl_Name@@ drinks some water from the well.\n" }),
               P_FOOD_SOAK: 10,
               P_FOOD_HEAL: 0]),
    P_LONG: "Some dirty water, but you can drink it.\n"]),v_puddle);
  v_flowers=AddVItem( ([
    P_IDS:  ({"flower","flowers"}),
    P_ADS:  ({"beautiful"}),
    PV_ITEM_LOCATION: #'clone_flowers,
    P_AMOUNT: 3,
    P_LONG: "Some beautiful flowers, right present for a nice girl.\n"]));


  // Exits
  AddExit("north","./36x60");
  AddExit("south","./orcstreet2");
}

