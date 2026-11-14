/* A room in the house of ende */

#include <rooms.h>
inherit "/p/houses/common/room/room";

create() {
  ::create();
  SetIntShort("Garden, the pool");
  SetIntLong("The decadently large swimming pool floating just over the lawn catches your\neye, you don't even see the rest of the garden, which stretches to all\ndirections.\n");
  AddExit("north","/d/archwiz/common/houses/ende/001");
  AddExit("south","/d/archwiz/common/houses/ende/201");
  AddExit("east","/d/archwiz/common/houses/ende/111");
  AddItem("/p/houses/common/obj/pool",REFRESH_HOME);
}
