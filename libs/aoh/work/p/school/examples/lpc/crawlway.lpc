#include <properties.h>

inherit "/d/archwiz/common/std/room";

varargs void create() {

  ::create();

  Set(P_INT_SHORT, "Crawlway between Example Dungeons");
  Set(P_INT_LONG,
"You are in a low dark crawlway. To the north and to the south you see "
"light shimmering.\n"
             );
  AddExit("north", "/d/archwiz/common/lpc/entrance");
  AddExit("south", "/p/school/examples/health/exroom1");
}
