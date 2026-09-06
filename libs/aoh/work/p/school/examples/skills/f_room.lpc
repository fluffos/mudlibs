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
  SetIntShort("in the deep forest");
  SetIntLong("Just demonstration...go back to the east from here.\n");

  SetIntLight(0);
  SetOutdoors(1);

  Set(P_REGION, REGION_FOREST);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({2100,2000,0}));

  AddExit("east","./d_room");
}
