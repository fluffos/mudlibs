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
  SetIntShort("outside a hut");
  SetIntLong("Just demonstration...go back to the east from here.\n");

  SetIntLight(25);
  SetOutdoors(1);

  Set(P_REGION, REGION_FOREST);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({2400,2000,0}));

  AddExit("east","./secret_room");
}
