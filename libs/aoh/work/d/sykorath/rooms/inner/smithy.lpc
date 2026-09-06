/* the armoury
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

create()
{
  ::create();
  SetIntShort("Armoury");
  SetIntLong(
    "This is the main smithy of the town. The room is enclosed by walls "
    "of heavy stone, blackened by forge placed in the middle of the room. "
    "A large, white-hot fire is blazing on the forge, and shadows are "
    "playing on the walls. A heavy, black anvil stands besides the forge, "
    "and the smith's tools are arranged beside it. The exit is to the "
    "west.\n"); 

  SetIndoors(1);
  SetCoordinates( ({ ({640,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"smithy","armoury"}),
    P_ADS:  ({"main"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"fireplace","fire-place"}),
    P_LONG: "It's an usual fireplace. You can find such a fireplace in "
            "nearly every armoury.\n" ]) ); 
  AddVItem( ([
    P_IDS:  ({"walls","wall"}),
    P_LONG: "The walls are crude constructions from black stones.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"stone","stones"}),
    P_ADS:  ({"black","heavy"}),
    P_LONG: "This are the black stones found in abundance in the "
            "forest near the city.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"soot"}),
    P_ADS:  ({"black"}),
    P_LONG: "Black soot from the fire hangs from the ceiling.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"forge"}),
    P_ADS:  ({"large"}),
    P_LONG: "This is a large forge with powerful bellows. A large, hot "
            "fire is blazing there.\n" ]) );
  AddDetail("bellows", 
    "The large hide bellows are used to heat up the fire.\n");
  AddVItem( ([
    P_IDS:  ({"fire"}),
    P_ADS:  ({"large","hot","white","hot"}),
    P_LONG: "The fire is extremely hot. Sparks are flying up from "
            "it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"sparks","spark"}),
    P_ADS:  ({"bright"}),
    P_LONG: "Bright sparks from the fire are lighting up the "
            "darkness.\n" ]) );
  AddVItem( ([ 
    P_IDS:  ({"shadows","shadow"}),
    P_LONG: "The shadows created by the fire are dancing ghostly over "
            "the walls.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"anvil"}),
    P_ADS:  ({"black","heavy"}),
    P_LONG: "The anvil is a monstrous piece of black iron. It looks as "
            "though it could survive centuries.\n" ]) ); 
  AddVItem( ([
    P_IDS:  ({"iron"}),
    P_ADS:  ({"black"}),
    P_LONG: "The anvil (for example) consists of it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"tools","tool"}),
    P_LONG: "Vylonds tools are of excellent quality, but they have a "
            "magical aura that protects strangers from touching them.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"masterpiece","masterpieces"}),
    P_LONG: "There are really excellent swords and axes hanging on the "
            "wall. Too bad that Vylond doesn't want to sell these fine "
            "weapons.\n" ]) );  
  AddDetail("coal","It is glowing onto the forge.\n");

  /* shop handling */
  SetIdentify(0);
  SetAppraise(0);
  SetSell(0);

  /* items */
  SetShopkeeper(NPC("smith"));

  /* exits */
  AddExit("west","./mainplazae");

  Set(P_INT_WIZMSG,
    "%^RED%^check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

