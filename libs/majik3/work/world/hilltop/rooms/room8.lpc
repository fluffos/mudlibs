inherit ROOM;

#include "../path.h"

create_room ()
{
  object ob;

  set_outdoors (4);
 
  set_short ("Plaque of Explorers");
  set_long (
    "You are standing in the hill near legendary hilltop of the gods "
  + "which is just few steps to the north. There is also a blessed "
  + "and magical plaque of explorers which keeps track of all good "
  + "adventurers. Legend says it is a gift from the god called Dazzt.\n");

  add_exit ("north", ROOM_PATH + "room9");
  add_exit ("west", ROOM_PATH + "room7");

  ob = load_object (ITEM_PATH + "plaque");
  ob->move (THOB);
  ob = load_object ("/daemon/statistics");
  ob->move (THOB);
  ob = load_object (ITEM_PATH + "temperature");
  ob->move (THOB);
}
