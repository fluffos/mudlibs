/* A room in the house of joan */

#include <rooms.h>
inherit "/p/houses/common/room/room";

varargs void create() {
  ::create();
  SetIntShort("Joan's swimming pool");
  SetIntLong("You enter a large room with a swimming pool inside. Looks like one can\nhave a lot of fun here... and sure Joan and Mistral have it!\n");
  AddExit("south","./121");
  AddExit("west","./011");
  AddItem("/p/houses/common/obj/pool",REFRESH_NONE);
}
