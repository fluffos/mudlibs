// part of the mainplaza of the town
// made by magictcs - 22 may 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

create(arg)
{
  if(::create(arg)) return 1;
  SetIntShort("Armoury");
  SetIntLong(
    "This is the main smithy of the town. The room is enclosed by walls\n"
    "of heavy stone, blackened by forge placed in the middle of the room.\n"
    "A large, white-hot fire is blazing on the forge, and shadows are\n"
    "playing on the walls. A heavy, black anvil stands besides the forge,\n"
    "and the smith's tools are arranged beside it. The exit is to the\n"
    "west.\n"); 
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"smithy","main smithy"}),#'IntLong);
  AddDetail(({"fireplace","fire-place"}),
    "It's an usual fireplace. You can find such a fireplace in nearly every\n"
    "armoury.\n"); 
  AddDetail(({"walls","wall"}),
    "The walls are crude constructions from black stones.\n");
  AddDetail(({"stone","stones","black stone","black stones","heavy stone",
    "heavy stones"}), 
    "This are the black stones found in abundance in the forest near the\n"
    "city.\n");
  AddDetail(({"soot","black soot"}),
    "Black soot from the fire hangs from the ceiling.\n");
  AddDetail(({"forge","large forge"}),
    "This is a large forge with powerful bellows. A large, hot fire is\n"
    "blazing there.\n");
  AddDetail("bellows", 
    "The large hide bellows are used to heat up the fire.\n");
  AddDetail(({"fire","large fire","hot fire","white-hot fire",
    "large white-hot fire"}),
    "The fire is extremely hot. Sparks are flying up from it.\n");
  AddDetail(({"sparks","spark","bright sparks","bright spark"}),
    "Bright sparks from the fire are lighting up the darkness.\n");
  AddDetail(({"shadows","shadow"}),
    "The shadows created by the fire are dancing ghostly over the walls.\n");
  AddDetail(({"anvil","black anvil","heavy anvil","heavy black anvil"}),
    "The anvil is a monstrous piece of black iron. It looks as though it\n"
    "could survive centuries.\n"); 
  AddDetail(({"iron","black iron"}),
    "The anvil (for example) consists of it.\n");
  AddDetail(({"tools","tool"}),
    "Vylonds tools are of excellent quality, but they have a magical aura\n"
    "that protects strangers from touching them.\n");
  AddDetail(({"masterpiece","masterpieces"}),
    "There are really excellent swords and axes hanging on the wall. Too\n"
    "bad that Vylond doesn't want to sell these fine weapons.\n");  
  AddDetail("coal","It is glowing onto the forge.\n");
  SetIdentify(0);
  SetAppraise(0);
  SetSell(0);
  SetShopkeeper(NPC("smith"));
  AddExit("west","./mainplaza");
}

