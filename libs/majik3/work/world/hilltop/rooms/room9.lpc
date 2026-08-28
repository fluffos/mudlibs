inherit ROOM;

#include "../path.h"

int running;

create_room ()
{
  set_outdoors (4);

	set_no_clean_up(1);
  set_short ("Legendary Hilltop of the Gods");
  set_long (
    "You are standing in the blessed ground of the gods. The place where "
  + "gods' magical flying room crashed. You can still see some parts of "
  + "that mystical room around you. Maybe the blessed plaque of explorers "
  + "was once in the flying room too. You wonder why the gods let their "
  + "toy to crash here.\n");

  add_exit ("south", ROOM_PATH + "room8");
  add_exit ("down", ROOM_PATH + "wizapp");
  add_object (MONSTER_PATH + "aberax");
  add_object (ITEM_PATH + "pendulum");
}
