#include <room.h>
#include <areas.h>
#include <door_defs.h>
#include <room_defs.h>

#include "dirs.h"

object ob;
object *mush;

void reset_room();

void
create_room()
{
    set_short("Small closet");
    set_long(
      "This is a small empty closet. It has been unused for years.");
    add_exit("crack", GDIR + "rooms/patch");
    set_light_level(LT_DIM);
    set(ROOM_WD,WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    if ((ob = clone_object(DOOR_FILE))) {
	ob->add_door(
	  "It is a heavy wooden door.",
	  "west", GDIR + "rooms/attic", "fine steel",
	  "youcanthavethiskey", 1, 0, 1, 60,
	  "It is a quite complex lock, but not impossible.");
    }
    mush = ({});
    reset_room();
}
void reset_room()
{
    int i;
    object shroom;

    mush -= ({ 0 });
    if (sizeof(mush) > 3) return;

    //   if (ob->query(DOOR_IS_CLOSED))
    //   {
    for(i=0;i < (8) * (random(4) + 1);i++)
    {
	shroom = clone_object(AREA_ISLANDS+"obj/mushroom");
	move_object(shroom,this_object());
	mush += ({ shroom });
    }
    //  }
}

void init_room()
{
    object shroom;
    mush -= ({ 0 });
    if (sizeof(mush) < 10)
	if (!random(10))
	{
	    this_object()->tell_here("A mushroom suddenly pops outta \
the floor!");
	    shroom = clone_object(AREA_ISLANDS+"obj/mushroom");
	    move_object(shroom,this_object());
	    mush += ({ shroom });
	}
}
