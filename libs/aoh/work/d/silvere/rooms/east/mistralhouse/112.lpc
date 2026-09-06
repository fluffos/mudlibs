/* A room in the house of joan */

#include <rooms.h>
inherit "/p/houses/common/room/room";

varargs void create() {
  ::create();
  SetIntShort("a room in the house of joan");
  SetIntLong("You've entered the bathroom.\n");
  AddExit("north","./012");
  AddExit("down","./111");
  AddExit("east","./122");
  AddItem("/p/houses/common/obj/faucet",REFRESH_NONE);
//  AddItem("/players/taurec/obj/shower",REFRESH_NONE);
}
