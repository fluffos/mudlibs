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
  SetIntShort("on a huge tree");
  SetIntLong("Just demonstration...go back down from here.\n");

  SetIntLight(0);
  SetOutdoors(1);

  Set(P_REGION, REGION_FOREST);
  Set(P_TEMPERATURE,20);
  SetCoordinates( ({3000,2000,100}));

  AddExit("down","./climb_room");
}
