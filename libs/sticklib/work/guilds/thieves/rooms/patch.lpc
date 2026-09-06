#include <room.h>
#include <room_defs.h>
#include "dirs.h"

object ob;
object *mush;

void reset_room();

void
create_room()
{
    set_short("Mushroom patch");
    set_long("A small mushroom patch, Dont get too greedy!");
    set_light_level(LT_DIM);
    set(ROOM_WD,WD_INDOORS);
    set(ROOM_GUILD);
    set(PREVENT_TELEPORT);

    mush = ({ });
    add_exit("crack", GDIR + "rooms/closet");

}

void reset_room()
{
    int i;
    object shroom;

    mush -= ({ 0 });
    if (sizeof(mush) > 3) return;


    for(i=0;i < (8) * (random(4) + 1);i++)

    {
	shroom = clone_object(AREA_ISLANDS+"obj/mushroom");
	move_object(shroom,this_object());
	mush += ({ shroom });
    }

}
void init_room()
{
    object shroom;
    mush -= ({ 0 });
    if (sizeof(mush) < 10)
	if (!random(10))
	{
	    this_object()->tell_here("A mushroom suddenly pops outta \
the ground!");
	    shroom = clone_object(AREA_ISLANDS+"obj/mushroom");
	    move_object(shroom,this_object());
	    mush += ({ shroom });
	}
}

