inherit ROOM;

#include "../path.h"

create_room ()
{
  set_light (1);
  set_outdoors (1);
 
  set_short ("Hilltop Inn");
  set_long (
    "You are inside a quiet village inn. The air here is warm "
  + "but silent. This seems to be the only inn here in "
  + "Hilltop village. The furnishings look new, as if the inn had "
  + "only been open a few months.\n");

  add_exit ("west", ROOM_PATH + "room2");
  add_exit ("down", ROOM_PATH + "roulette");
  add_exit ("reincarnation", "/world/misc/race");
  add_object (ITEM_PATH + "board");
  add_object (ITEM_PATH + "exp_plaque");
  add_object ("/world/creek/items/fountain");
}
