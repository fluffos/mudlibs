// room along the north wall
// made by Gwenderon 03-Sep-1997

#include <rooms.h>
#include <coordinates.h>
#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  Set(P_INDOORS,0);
  Set(P_INT_SHORT,"Somewhere along the north wall of the garden");
  Set(P_INT_LONG,
    "The inner city wall stretches itself to the west and east. Looking "
    "around you only see lots of black, ill trees and some healthy green "
    "ones. The grass still looks ill with its yellow-black color. "
    "Through some trees to the south you see lots of flowers.\n");

  Set(P_INT_WIZMSG,
  " East: another step into the garden.\n"
  " South: After 1 step the flower garden, 2 the mainplaza.\n"
  " West: NW corner of garden.\n");


  /* details */

  AddDetail(({"garden","place","this place"}),#'IntLong);

  AddDetail(({"trees","black trees","black ill trees","ill trees",
    "black,ill trees"}),
            "You remember the stories sung by an uncountable "
            "number of bards about the great battle. Those trees "
            "must be a reminder of that dark age. Half dead, chared "
            "and gnarled though they managed to survive and make this "
            "an eerie place. Though some new, healthy ones obviously managed "
            "to grow on this ground.\n");

  AddDetail("tree",
            "This tree obviously was very unlucky. Its split right in the "
            "middle. Maybe it was hit by lightning.\n");

  AddDetail(({"walls","wall","city wall","inner city wall"}),
            "The inner city wall serves to divide this city into two "
            "main parts; the inner and outer city. It looks very sturdy "
            "and the fact that it survived the great battle with only "
            "some minor damage gives its builders even more credit. "
            "Its surface looks black and the stone slightly molten.\n");

  AddDetail(({"surface","black surface"}),
            "The surface of the stone wall is churned black from the "
            "great fire. From the signs of destruction this part of "
            "the wall obviously suffered greatly. The slightly molten "
            "stone is a sign for the intense heat having been at work "
            "here. The wall though looks quite strong and formidable "
            "still.\n");

  AddDetail("grass",
            "The grass looks very ill with its yellow-black color. "
            "Usually grass recovers fast when it gets burned but "
            "something seems to prevent any healing to the grass in "
            "this garden. Its like some poison running through the "
            "soil here.\n");


  SetIntSmell("You smell the burned trees and grass and decide not to "
              "take a too deep breath.\n");

  SetIntNoise("Strange, now you recognize that no sound usually found "
              "in a garden can be heard.\n");

  Set(P_INT_MAP,"garden");
  Set(P_REGION,REGION_JUNGLE);
  Set(P_COORDINATES, ({ ({ 30,10,0 }), C_SYKORATH }) );
  Set(P_NOWAY_MSG,"Forcing your way through the trees to run into a "
             "wall wont be a good idea.\n");


  /* Exits */
  AddExit("south","./garden8");
  AddExit("east","./garden4");
  AddExit("west","./garden2");

}

