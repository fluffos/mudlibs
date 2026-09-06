#include <rooms.h>
#include <skills.h>
#include <regions.h>
#include <moving.h>
#include <properties.h>
#include <coordinates.h>


inherit "/std/room";

create()
{
  ::create();
  SetIntShort("over the lake");
  SetIntLong("Just demonstration...go back to the west from here.\n");

  SetIntLight(0);
  SetOutdoors(1);

  Set(P_REGION, REGION_MEADOW);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({1900,2000,0}));


  AddExit("west","./d_room");
}
