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
  string v_street,v_house;
  ::create();
  SetIntShort("On the orc street");
  SetIntLong(
    "This is part of the orc street. A pile of rotten clothes is lying on "
    "the ground. East is the backside of a small house.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({380,680,0}), C_SYKORATH }));
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
  v_house=AddVItem( ([                  // (small) house
    P_IDS:  "house",
    P_ADS:  "small",
    P_PREPS: ({"of"}),
    P_LONG: "You cannot see much from here. Why not look for an entrance "
            "into it?\n" ]) );
  AddVItem( ([                          // backside
    P_IDS:  "backside",
    P_LONG: "It's only the backside of a small house. There is no entrance "
            "here. \n" ]) );
  AddVItem( ([                          // backside of (small) house
    P_IDS:  "backside",
    P_LONG: "It's only the backside of a small house. There is no entrance "
            "here. \n" ]),v_house );
  AddVItem( ([
    P_IDS:  ({"pile","pile of clothes"}),
    P_LONG: "Just a pile of rotten old clothes. Someone has dropped them "
            "here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"clothes"}),
    P_ADS:  "rotten",
    P_LONG: "Some rotten clothes, not very useful to cover any part of your "
            "body.\n" ]) );


  // Exits
  AddExit("north","./orcstreet3");
  AddExit("southeast","./orcstreet5");
}

