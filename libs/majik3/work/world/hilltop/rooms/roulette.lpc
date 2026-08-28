inherit ROOM;

#include "../path.h"

create_room ()
{
    set_light (1);
    set_outdoors (0);
    set_short ("Roulette wheel");
    set_long ("You are standing in a roulette room. There is a roulette "+
      "wheel in the middle of the room. If you have some money, go ahead "+
      "and try your luck!\n");

    add_exit ("up", ROOM_PATH + "room1");
    add_object (MONSTER_PATH + "jack");
    add_object (ITEM_PATH + "roulette");
    add_object (ITEM_PATH + "slots");
    add_object (ITEM_PATH + "mplaque");

    set_sounds (256, ({"You hear some sounds above you.\n",
	"You feel greedy.\n", "You want to play!\n" }));
}
