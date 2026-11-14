/* A room in the house of ende */

#include <rooms.h>
inherit "/p/houses/common/room/home";

config() {
  SetIntShort("Entrance Hall");
  SetIntLong("You are standing in the entrance hall of Ende's house.\nTwo broad stairs arc towards the upper floor.\nA little door in a corner reveals some steps leading down.\n");
  AddExit("up","/d/archwiz/common/houses/ende/122");
  AddExit("down","/d/archwiz/common/houses/ende/120");
  AddExit("south","/d/archwiz/common/houses/ende/221");
  AddExit("north","/d/archwiz/common/houses/ende/021");
  AddExit("west","/d/archwiz/common/houses/ende/111");
  AddExit("east","/d/archwiz/common/houses/ende/garden1");
  AddItem("/d/avalon/common/obj/bed",REFRESH_NONE);
  AddItem("/d/woodland/common/furniture/sofa",REFRESH_NONE);
  SetEnter("west");
}
