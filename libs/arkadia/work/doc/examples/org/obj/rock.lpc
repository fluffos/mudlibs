/*
 * rock.c
 */

/*
 * The rock that can be found in cave2.c. If the player was lucky he might
 * had found a gem instead.
 */
#pragma strict_types

inherit "/std/object";

#include "ex.h"			/* Always good to have.... */
#include <stdproperties.h>	/* Properties */

/*
 * The create routine, called create_object() in this case since we inherit
 * /std/object.c
 */
void
create_object()
{
    set_name("rock");
    set_adj("dull");
    set_long("There is nothing special about that dull piece of rock.\n");

    add_prop(OBJ_I_VALUE, 3);	/* Value, 3 copper coins */
    add_prop(OBJ_I_WEIGHT, 57);
    add_prop(OBJ_I_VOLUME, 32);
}

/*
 * Here we'll make the rock recoverable. Not that this is a valuable object or
 * anything but maybe someone grows found to it? To make it recoverable we have
 * to let query_recover() return the filename of this object. There are no
 * special variables that need to be save, so the last character should be a
 * ':' after the filename.
 */
string
query_recover()
{
    return EX_OBJ + "rock:";
}

