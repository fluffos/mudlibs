/* A room in the house of ende */

#include <rooms.h>
inherit "/p/houses/common/room/room";

create() {
  ::create();
  SetIntShort("Living room");
  SetIntLong("Some mistake seems to have happend during the arragement of the furniture in \nthis living room. But the room is really big enough to give a home for the two \ntables and three sofas it holds. A soft carpet gives you a comfortable feeling\nwhile walking through it.\n");
  AddExit("north","/d/archwiz/common/houses/ende/111");
  AddItem("/d/woodland/common/furniture/sofa",REFRESH_NONE);
  AddItem("/d/woodland/common/furniture/sofa",REFRESH_NONE);
  AddItem("/d/woodland/common/furniture/sofa",REFRESH_NONE);
  AddItem("/d/woodland/common/furniture/table",REFRESH_NONE);
  AddItem("/d/woodland/common/furniture/table",REFRESH_NONE);
  AddItem("/p/houses/common/obj/picture",REFRESH_NONE);
}
