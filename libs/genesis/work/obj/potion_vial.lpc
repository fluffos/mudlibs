/*
 * /obj/potion_vial.c
 *
 * Mixing potions with the mortar requires a vial. What is actually checked
 * in the name "vial" only, so any object with that name will do, but this is
 * a convenient standard. /Olorin
 *
 * Made this heapable at the expensive of it being to be exclusively used for
 * potions.
 */

#pragma strict_types

inherit "/std/heap";

#include <macros.h>
#include <stdproperties.h>

/*
 * Function name: create_heap
 * Description  : Constructor.
 */
public void
create_heap()
{
    set_name("vial");
    set_pname("vials");
    add_name("_std_potion_vial");
    set_adj("empty");
    set_long("An empty vial. You could fill a potion into it, but that " +
        "is all it is good for.\n");
    add_prop(HEAP_I_UNIT_VOLUME, 100);
    add_prop(HEAP_I_UNIT_WEIGHT, 50);
    add_prop(HEAP_I_UNIT_VALUE, 24);
    add_prop(HEAP_S_UNIQUE_ID, "_std_potion_vial");
    add_prop(OBJ_M_NO_SELL, 1);
    set_heap_size(1);
}

/*
 * Function name: init_recover
 * Description  : Called to reset the heap size upon recovery.
 * Arguments    : string arg - the heap size (hopefully).
 */
void
init_recover(string arg)
{
    int num = atoi(arg);

    if (num) set_heap_size(num);
}

/*
 * Function name: query_recover
 * Description  : We allow this standard potion vial to recover.
 * Returns      : string - the recovery string.
 */
public string
query_recover()
{
    return MASTER + ":" + num_heap();
}
