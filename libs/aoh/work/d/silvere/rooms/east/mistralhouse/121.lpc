/* A room in the house of joan */

#include <rooms.h>
inherit "/p/houses/common/room/room";

varargs void create() {
  ::create();
  SetIntShort("a room in the house of Joan and Mistral");
  SetIntLong("You are standing in an empty room.\n");
  AddExit("north","./021");
  AddItem("/p/houses/common/obj/dartboard",REFRESH_NONE);
  AddItem("/p/houses/common/obj/sofa",REFRESH_NONE);
  AddItem("/p/houses/common/npc/house_bat",REFRESH_NONE);
  AddItem("/p/houses/common/obj/goldfishbowl",REFRESH_NONE);
}
