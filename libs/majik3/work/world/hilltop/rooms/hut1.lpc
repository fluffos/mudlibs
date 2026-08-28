inherit ROOM;

#include "../path.h"

create_room ()
{
  set_light (1);
  set_outdoors (1);
 
  set_short ("Hut");
  set_long (
    "You are standing inside hut which seems to be look point of the "
  + "hilltop village. Usually here stands a guard watching all traffic "
  + "going in and out from the village.\n");

  add_exit ("out", ROOM_PATH + "room13");
  add_object (MONSTER_PATH + "guard");
  add_object (ITEM_PATH + "hacker");
}

scribe (string str)
{
  tell_room (THOB, "You can see someone walking down there.\n");

  call_out ("do_scribe", 1 + random(2), str);

  return 1;
}

do_scribe (string str)
{
  object ob;

  ob = present ("guard", THOB);

  if (ob)
    {
      ob->do_scribe (str);
    }
  return 1;
}
