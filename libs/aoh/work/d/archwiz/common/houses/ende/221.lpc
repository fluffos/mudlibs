/* A room in the house of ende */

#include <rooms.h>
inherit "/p/houses/common/room/room";

create() {
  ::create();
  SetIntShort("News room");
  SetIntLong("In this room you can check your eyes. If you can read the news on the board\nwhile sitting on the couch, your eyes are not bad.\n");
  AddExit("north","/d/archwiz/common/houses/ende/121");
  AddItem("/d/halfling/magictcs/obj/allnews",REFRESH_NONE);
  AddItem("/d/woodland/common/furniture/sofa",REFRESH_NONE);
}
