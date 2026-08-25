/*
 * /std/bowstring.c
 *
 * This is the base class for bowstrings, inherit
 * and alter this if you want create a bowstring
 * of your own. The bowstring does not alter the
 * qualities of the bow, but it is nice to find
 * the same bowstring when you unstring your bow,
 * hence the reason for this class.
 */

inherit "/std/object";
inherit "lib/keep";

#include <macros.h>
#include <stdproperties.h>

/*
 * Function name: create_bowstring
 * Description  : Redefine this function to create your own
 *                bowstring.
 */
private void
create_bowstring()
{
}

/*
 * Function name: create_object
 * Description  : Sets some basic default values for bowstring
 *                Redefine create_bowstring to alter them.
 */
public nomask void
create_object()
{
    set_name("bowstring");
    set_long("It's a typical bowstring made from a strong fiber that " +
             "has been spun and waxed.\n");
    add_prop(OBJ_I_VALUE, 12);
    add_prop(OBJ_I_WEIGHT, 14);
    add_prop(OBJ_I_VOLUME, 11);
    set_keep();
    create_bowstring();
}

/*
 * Function name: is_bowstring
 * Description  : A function that makes it easy to filter
 *                out bowstrings among other objects.
 * Returns      : Allways returns 1.
 */
public nomask int
is_bowstring()
{
    return 1;
}

/*
 * Function name: query_recover
 * Description  : Called to make this bowstring recoverable, and
 *                to make sure the keep status is kept.
 * Returns      : A string representation of the state to be kept.
 */
string
query_recover()
{
    return MASTER + ":" + query_keep_recover() + "#";
}

/*
 * Function name: init_recover
 * Description  : Restores the kept state of the bowstring after
 *                armageddon.
 * Arguments    : arg (string) - The recover string.
 */
void
init_recover(string arg)
{
    init_keep_recover(arg);
}
