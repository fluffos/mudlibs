/* This room once will contain examples for std/drink and std/food items
 * It also shows how to program a place for refilling empty vessels
 */
inherit "/std/room";

#include <rooms.h>
#include <properties.h>

varargs void create() {
  ::create();
  SetIntShort("a test room");
  SetIntLong(
"You are in the first example room of the AW of Health. At the north wall you "
"can see a water tap. A staircase leads up to the Health office. To the east "
"and west you can find example pubs programmed with /std/pub. A crawlway leads north.\n"
"This room contains programming examples for /std/drink and /std/food. "
"If it is empty, try 'reset'.\n");
  /* SetIntLight(1); */
  AddDetail(({"tap","faucet"}),"Maybe you can refill empty bottles here?\n");
  AddItem("/p/school/examples/health/exfood",REFRESH_REMOVE);
  AddItem("/p/school/examples/health/exdrink1",REFRESH_REMOVE);
  AddItem("/p/school/examples/health/exdrink2",REFRESH_REMOVE);
  AddExit("east","/p/school/examples/health/exroom2");
  AddExit("west","/p/school/examples/health/exroom3");
//  AddExit("up","/d/archwiz/common/health/office");
  AddExit("north", "/p/school/examples/lpc/crawlway");
  AddRoomCmd("reset","my_reset");	/* call reset directly! */
  Set(P_REFILL,"water");	/* the refill stuff --- that's all */
  Set(P_INDOORS,1);
}

int my_reset() { ::reset(); return 1; }
