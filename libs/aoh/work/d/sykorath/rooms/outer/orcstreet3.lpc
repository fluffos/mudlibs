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

create() {
  string v_street,v_entrance;
  ::create();
  SetIntShort("On the orc street");
  SetIntLong(
    "This is part of the orc street leading to the slums where orcs live. "
    "A lot of dirt is lying on the ground. "
    "To the southeast is a small house. A sign is nailed above he entrance "
    "door.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({380,660,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetMap("outer");

  // details:
  v_street=AddVItem( ([                 // street, orc street
    P_IDS:  "street",
    P_ADS:  ({"orc"}),
    P_PREPS: ({"of"}),
    P_LONG: "The street is really dirty. A lot of people seems to run around "
            "here.\n" ]) );
  AddVItem( ([                          // part of street, part of orc street
    P_IDS:  ({"part"}),
    P_LONG: "The street is really dirty. A lot of people seems to run around "
            "here.\n" ]),v_street );
  AddVItem( ([                          // dirt
    P_IDS:  "dirt",
    P_LONG: "The nearer you come to the slums of the orcs, the more dirt "
            "you see.\n" ]) );
  AddVItem( ([                          // (dirty) ground
    P_IDS:  "ground",
    P_ADS:  "dirty",
    P_LONG: "The ground is really dirty.\n"]) );
  AddVItem( ([                          // house
    P_IDS:  "house",
    P_ADS:  "small",
    P_LONG: "The house looks a bit small. It's not the house of a large "
            "inhabitant of this city.\n" ]) );
  AddVItem( ([                          // entrance
    P_IDS:  "entrance",
    P_PREPS: ({"above"}),
    P_LONG: "The entrance is the wooden door you see to the southeast. "
            "It leads into the house. Maybe you should take a short look "
            "into it?\n" ]) );
  AddVItem( ([                          // (wooden) sign above antrance
    P_IDS:  "sign",
    P_ADS:  "wooden",
    P_LONG: "There is only one word written on the wooden wign:\n"
            "  --> Shoemaker <--\n" ]),v_entrance );
  AddVItem( ([                          // (wooden) sign
    P_IDS:  "sign",
    P_ADS:  "wooden",
    P_LONG: "There is only one word written on the wooden wign:\n"
            "  --> Shoemaker <--\n" ]) );
  AddVItem( ([                          // slum,slums
    P_IDS:  ({"slum","slums"}),
    P_LONG: "The slums are further to the south. Be careful to go "
            "there!\n" ]) );

  // Exits
  AddExit("northwest","./orcstreet2");
  AddExit("south","./orcstreet4");
  AddDoor("southeast","./shoemaker",
    ([ P_SHORT:    "a wooden door",
       P_LONG:     "A small wooden door\n",
       P_DOORCODE: "syko_shoemakerdoor",
       P_ADS:      ({"wooden","small"}),
    ]) );
}

