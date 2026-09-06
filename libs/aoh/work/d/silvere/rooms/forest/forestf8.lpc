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

inherit FORESTROOM;

varargs void create()
{
  ::create();
  SetIntShort("a forest");
  SetIntLong(
"You are standing in a forest\n");

  AddDetail("forest",#'IntLong /*'*/);

  AddExit("north","./foreste8");
  AddExit("east","./forestf9");

}
