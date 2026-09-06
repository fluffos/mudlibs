#include <rooms.h>
#include <regions.h>
#include <properties.h>
#include <coordinates.h>
#include <moving.h>
#include <skills.h>
#include <herbs.h>
#include <nightday.h>
#include <msgclass.h>
#include "forest.h"

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("a healerhut");
  SetIntLong(
"You are standing in a healerhut\n");

  SetIndoors(1);

  AddDetail("forest",#'IntLong /*'*/);

  AddExit("north","./foreste4");

}
