// northeast corner of the garden around mainplaza
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
  Set(P_INT_SHORT,"Northeast corner of garden");
  Set(P_INT_LONG,
    "The garden comes to an end here to the east and north blocked by "
    "the inner city wall. Most trees here are churned from a fire long "
    "ago and more dead than alive. To the south lots of those trees block "
    "your sight so you can not see far; the same to the west. "
    "The grass you are walking upon only grows "
    "up to short, yellow-black stubbles.\n");

  Set(P_INT_WIZMSG,
  " West: another step into the garden.\n"
  " South: Also garden.\n");


  /* details */

  AddDetail(({"garden","place","this place"}),#'IntLong);

  AddDetail("trees",
            "Burned in a great fire those trees are only a wretched "
            "remains of what they should be. Though its really a miracle "
            "how they survived on this dead soil. But because they still, "
            "after such a long time, have not recovered this cant be such "
            "a nice place.\n");

  AddDetail("tree","Looking at your nearest tree you see it really "
            "does not resemble any tree you ever saw. Almost burnt "
            "to its core it still is not dead yet. No leaves grow on "
            "its churned branches and it seems to emit only death and "
            "decay.\n");

  AddDetail(({"walls","wall","city wall","inner city wall"}),
            "The inner city wall serves to divide this city into two "
            "main parts; the inner and outer city. It looks very sturdy "
            "and the fact that it survived the great battle with only "
            "some minor damage gives its builders even more credit. "
            "Several black spots cover its surface.\n");

  AddDetail(({"spots","black spots"}),
            "The black spots are a remainder of the great fire that "
            "brought havoc over the city. The fire was a result from "
            "the merciless battle that was fought between the city of "
            "light and the city of chaos. This city must have suffered"
            "severely during that battle.\n");

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
  Set(P_COORDINATES, ({ ({ 30,30,0 }), C_SYKORATH }) );
  Set(P_NOWAY_MSG,"Forcing your way through the trees to run into a "
             "wall wont be a good idea.\n");


  /* Exits */
  AddExit("south","./garden10");
  AddExit("west","./garden4");

}

