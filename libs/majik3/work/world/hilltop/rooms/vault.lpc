inherit ROOM;

int money;

#include "../path.h"

create_room ()
{
  object ob;
  set_light (0);
  set_short ("Post office's vault");
  set_long ("You are standing in the post office's little money vault "+
    "where they seem to save all their money.\n");
  restore_object ("/data/misc/vault");
  add_door ("up", ROOM_PATH + "room3", "door", "wooden", 0, 10 + random(30), 2);
  ob = clone_object ("/obj/money");
  ob->set_amount (money);
  ob->move (THOB);
}

init_room ()
{
  add_action ("do_get", "get");
  add_action ("do_drop", "drop");
}

do_get (string str)
{
  if (str == "coins")
    {
      money = 0;
      save_object ("/data/misc/vault");
      "/world/hilltop/rooms/room3"->do_alarm(THIS);
      THIS->set_alignx (THIS->query_alignx()-random(100));
      THIS->set_aligny (THIS->query_aligny()-random(100));
    }

  return 0;
}

int
do_drop (string str)
{
  int i;
  string what;
  object ob;

  if(sscanf (str, "%d %s", i, what) == 2)
    {
      money += i;
      save_object ("/data/misc/vault");
    }
  return 0;
}
