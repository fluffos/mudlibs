/* A room in the house of joan */

#include <rooms.h>
inherit "/p/houses/common/room/room";

varargs void create() {
  ::create();
  SetIntShort("Do not disturbe!");
  SetIntLong("Do not disturbe. No Wizards allowed in here ... please leave at once.\nThank you!\n Joan+Mistral\n");
  AddExit("west","./012");
  AddItem("/p/houses/common/obj/bed",REFRESH_NONE);
}
