#include <room.h>
#include <areas.h>

#include "../DEFS.h"

void
create_room()
{
    string *x;
    int i;

    set_short("Adamantite room");
    set_long("You are in a room made of pure adamantite. The stuff \
here - if it is here - is a set of perfect armor. Naturally this \
does not mean you can hand it to players! No, it is for testing. \
The armor, from /areas/practice/obj/, does follow the correct \
minimum weight and value rules, as far as I know.");
    set(ROOM_ISOLATED);
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);

    add_exit("out", AREA_PRACTICE + "start");

    x = ({
      "amulet", "belt", "boots", "bracers",
      "cloak", "gauntlets", "helmet", "leggings",
      "mask", "plate", "ring", "shield",
    });

    for (i = sizeof(x) - 1; i >= 0; i--)
	move_object(clone_object(OBJ_DIR + x[i]), this_object());

    replace_program(ROOM_FILE);
}

