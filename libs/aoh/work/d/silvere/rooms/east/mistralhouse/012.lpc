/* A room in the house of joan */

#include <rooms.h>
//inherit "/players/mistral/room/shieldroom";
inherit "/p/houses/common/room/room";

varargs void create() {
  room::create();
//  shieldroom::create();
  SetIntShort("Joan's and Mistral's bedroom\n");
  SetIntLong("This is the bedroom of Joan and Mistral. Nothing special here. It is just\nthe place where Mistral whispers words of love to his wife. What else\ncould happen here is not of any interest for any other player.\nIn a corner of the room there is standing a tree full of boomerangs.\n");
  AddExit("west","./002");
  AddExit("down","./011");
  AddExit("south","./112");
  AddExit("east","./022");
  AddItem("/p/houses/common/obj/bed",REFRESH_NONE);
//  AddItem("/players/mistral/obj/chair",REFRESH_NONE);
//  AddItem("/players/mistral/obj/xmastree",REFRESH_NONE);
//  SetAllowed(({"Joan","Mistral","Typo","Jr"}));
//  SetOtherRoom("/players/mistral/house/011");
//  SendMessage(1);
}
