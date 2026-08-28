#include "../path.h"

inherit ROOM;

create_room ()
{
  set_short ("Under the balcony");
  set_long (
    "You're standing behind the treepalace Que-Moran. The palace it"
  + "self is at least 150 feet above you so you're basically behin"
  + "d the enormour tree it is built on. Directly above you looms "
  + "a balcony of some sort. A strange elevator system has been bu"
  + "ilt here. Small path leads south from here.");


  add_object (ITEM_PATH + "elevator");
  set_outdoors (4);
}

init()
{
  ::init();
  add_action("do_ring","ring");
}
do_ring(string str)
{
  object ob;

  if (!str || str != "bell")
  {
    notify_fail ("Ring what?\n");
    return 0;
  }

  write ("You ring the bell a couple of times.\n");
  message ("3", THIS->query_cap_name() + " rings the bell.\n",ENV(THIS),THIS);
  
  ob = present("an elevator", ENV(THIS));

  if (ob)
    {
      message ("3", ob->query_cap_name() + " leaves up.\n", ENV(ob));
      ob->move (ROOM_PATH + "quebal");

      ROOM_PATH + "elevator"->add_exit ("out", file_name(ENV(ob)));
      ROOM_PATH + "elevator"->init(0);

      message ("3", ob->query_cap_name() + " arrives.\n", ENV(ob));
    }
  else
    {
      message ("3", "Nothing happens.\n", ENV(THIS));
    }

  return 1;
}
