/*
 * /std/arrow.c
 *
 * This is the base for all kinds of arrows that are
 * shot with bows. Inherit this class if you want to
 * create your own kind of arrows.
 *
 * Since /std/arrow is a heap object your need to give
 * it an unique id with set_projectile_id() or else it
 * might be absorbed by other heaps of arrows.
 *
 * See /doc/examples/weapons/black_feathered_arrow.c
 * for an example of an arrow.
 */

#pragma strict_types

inherit "/std/projectile";

#include <stdproperties.h>

/*
 * Function name: create_arrow
 * Description  : Constructor. Use this constructor to create arrow type
 *                projectiles.
 */
public void
create_arrow()
{
  return;
}

/*
 * Function name: get_projectile_long
 * Description  : Use this function to return the proper long description
 *                of this arrow.
 * Arguments    : string str     - the pseudo-item to describe. Not used in
 *                                 this routine. It's intercepted in long().
 *                object for_obj - the object trying to get the long.
 *                int num        - The number of arrows in this stack.
 * Returns      : string         - the description of the object or
 *                                 pseudo-item.
 */
string
get_projectile_long(string str, object for_obj, int num)
{
    return "The arrow" + 
        ((num == 1) ? " is" : "s are") + " unusually plain.\n";
}

/*
 * Function name: create_projectile
 * Description  : Constructor. This sets some internal state of the arrow
 *                Mask create_arrow instead if you want to create an
 *                arrow.
 */
public nomask void
create_projectile()
{
    set_name("arrow");
    set_pname("arrows");

    add_prop(HEAP_I_UNIT_WEIGHT, 22);
    add_prop(HEAP_I_UNIT_VOLUME, 26);
    add_prop(HEAP_I_UNIT_VALUE, 20);
    set_hit(40);
    set_pen(40);
    set_heap_size(12);
    set_projectile_id("plain_arrow");
    create_arrow();
}

/*
 * Function name: is_arrow
 * Description  : A function that indentifies this projectile as an arrow
 *                type projectile.
 * Returns      : (int) 1 - Since this is an arrow.
 */
public nomask int
is_arrow()
{
    return 1;
}
