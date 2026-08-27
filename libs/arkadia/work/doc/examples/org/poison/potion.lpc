/*
 * /doc/examples/poison/potion.c
 * Written by Quis, 920605
 */

inherit "/std/potion";
#include <stdproperties.h>

int no_poison;

/*
 * We just make a generic potion, with no healing powers.
 */

create_potion()
{
    set_soft_amount(10); 
    set_alco_amount(0); 
    set_name("potion"); 
    set_adj("bubbling");
    set_long("This potion bubbles and fumes.\n"); 

    /* Magical poison can be magically dispelled, but we resist a little. */
    set_magic_res(40); /* This potion is a little resistive to dispelling */

    add_prop(OBJ_I_VALUE, 25);
    add_prop(OBJ_I_WEIGHT, 103);
    add_prop(OBJ_I_VOLUME, 76);
    add_prop(OBJ_S_WIZINFO, "A potion of poison!\n");
    add_prop(MAGIC_AM_MAGIC, ({ 10, "poison" })); /* This is magical poison */
    add_prop(MAGIC_AM_ID_INFO, ({
	"You feel very uncertain about this potion.\n", 10,
	"You should probably get rid of this potion.\n", 30,
	"This potion contains poison!!!!! Don't quaff it.\n", 50 }) );
}

/*
 * This function is called if player wanted to quaff this object
 */
consume_me()
{
    object poison;

    if (no_poison)
	return;

/*
 * Now we create the poison.  We will just use the defaults, so no set_*
 * functions are required.  After we clone it, we move it to the
 * consuming living, then call the activating function, start_poison()
 */

    seteuid(getuid(this_object()));
    poison = clone_object("/std/poison_effect");
    if (poison)
    {
        poison->move(this_player());
	poison->set_strength(20);
        poison->start_poison();
    }
    else 
	write("Failed to load poison for some reason.\n"); 
}

cure_poison(int strength)
{
    if (strength > 20)
    {
	no_poison = 1; /* Poison was removed from the potion */
   	return 1;
    }

    return 0;
}

