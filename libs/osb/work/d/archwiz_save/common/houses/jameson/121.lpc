/* A room in the house of jameson */

#include <rooms.h>
inherit "/p/houses/common/room/home";

config() {
  SetIntShort("the house of jAmeson and Julchen");
  SetIntLong("You are in the sweet home of jAmeson and Julchen.\nThis room creates a deep feeling of love, warmth, and harmony inside you.\nIf you listen carefully, you might hear jAmeson whispering:\n\"Julchen, ich liebe dich!\"\n");
  AddExit("down","/d/archwiz/common/houses/jameson/120");
  AddExit("east","/d/archwiz/common/houses/jameson/garden1");
  AddItem("/d/ireland/common/obj/stuff/poster",REFRESH_NONE);
  AddItem("/d/avalon/common/obj/bed",REFRESH_NONE);
  AddItem("/d/avalon/common/obj/faucet",REFRESH_NONE);
  AddItem("/d/avalon/common/obj/dustbin",REFRESH_NONE);
  AddItem("/d/halfling/magictcs/obj/allnews",REFRESH_NONE);
  AddItem("/p/houses/common/obj/wardrobe",REFRESH_NONE);
  SetEnter("west");
}
