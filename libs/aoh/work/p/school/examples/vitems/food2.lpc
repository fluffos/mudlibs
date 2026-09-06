/*
 * example 2 for eat-able vitems
 * Magictcs - 15 march 98
 *
 * demonstrate how to use the new property for vitems to allow to eat them
 */

/*
  How to use it:
  simplest version:

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    P_FOOD: ([ eat-mapping ]) ,
  ]) );

  or

  AddVItem( ([
    P_IDS:  ({"id1","id2",...}),
    P_ADS:  ({"ad1","ad2",...}),
    P_LONG: "long description of vitem...",
    P_FOOD: #'closure_to_clone_me_a_drink_to_eat ,
  ]) );

  NOTE: as long as our foods don't support properties - only the second
        version is correct!!!! ---> see examples

  it is possible to cascade the vitems (like the berry in our example!):
  eat berry from bush
  vitem#1 = bush
  vitem#2 = berry (cascaded to bush) 

*/ 

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>

inherit "/std/room";

// two vitem-ids:
string v_bush;
string v_berry;

//************************
// clone the object to eat
//************************
object clone_berry() {
  object ob;
  ob=clone_object("/std/food");        // use food - because no vessel!!!
  if (ob) {
    ob->SetShort("a berry");           // for the failure messages needed!
    ob->SetFoodKind("food");           // it is a food
                                       // (this line is not needed!)
    ob->SetFoodMsgs(({
      "You eat a berry from the bush.\n",
      "@@Pl_Name@@ eats a berry from the bush.\n" }));
    ob->SetFoodStuff(3);               // stuffs not so good *grins*
    ob->SetHeal(0);                    // but no healing effect!
    // we can add alcohol as well as any other possible setting!
    // maybe for fermented berries?!
    return ob;                         // the obj will be consumed in future
  }
  return 0;
}

// look at the bush:
string look_bush() {
  if (VQuery(v_berry,P_AMOUNT))
    return "It's an bush. You see some berries there.\n";
  return "It's an bush without berries left.\n";
}

// look at the berries
string look_berry() {
  if (VQuery(v_berry,P_AMOUNT)) 
    return "Some red berries, you can eat them.\n";
  return "There is no berry left here";
  // possible too:
  // return 0; --> 'You see nothing....'
}

//*******
// create
//*******
varargs void create() {
  ::create();
  SetIntShort("Example room 2");
  SetIntLong("Example room2:\n"
    "Try to look at the bush and the berry of it.\n"
    "Then try to eat the berry from bush.\n"
    "(You can eat ten berries!)\n"
    "A bush is here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  v_bush=AddVItem( ([
    P_IDS:  ({"bush"}),
    P_PREPS: ({"of","from"}),
    P_LONG: #'look_bush ]) );
  v_berry=AddVItem( ([
    P_IDS:  ({"berry","berries"}),
    P_ADS:  ({"red"}),
    P_FOOD: #'clone_berry,       // can be a mapping too!
    P_AMOUNT: 10,                // we want limit the number of berries!!!
    P_LONG: #'look_berry ]),v_bush);

  /* Exits */
  AddExit("west","./food1");
}

