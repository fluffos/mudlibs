// a fishbowl to illustrate open containers which can clone items

#define IS_FISHBOWL  "IsFishbowl"

#include <properties.h>
#include <rooms.h>
//#include <school.h>

inherit "/std/container";
inherit "/std/room/items";

void create()
{
  ::create();
  SetShort("a glass fishbowl");
  SetLong("A clear, glass fishbowl. It is round and filled with water.\n");

  AddId( ({ "fishbowl", "bowl" }) );

  Set(P_TRANSPARENCY, 1000);
  Set(P_MAX_WEIGHT, 2000);
  Set(P_PRECONTENT, "It contains:\n");

  Set(IS_FISHBOWL, 1);

  AddItem("/p/school/examples/container/goldfish", REFRESH_DESTRUCT);

}
