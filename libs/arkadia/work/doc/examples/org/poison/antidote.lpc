/*
 * /doc/examples/poison/antidote_potion.c
 * Written by Quis, 920605
 */

inherit "/std/potion";
#include <stdproperties.h>

/*
 * This potion looks just like the poisoned potion, he he he
 */
create_potion()
{
    set_soft_amount(10); 
    set_alco_amount(0); 
    set_name("potion"); 
    set_adj("bubbling");
    set_long("This potion bubbles and fumes.\n"); 

    add_prop(OBJ_I_VALUE, 125);
    add_prop(OBJ_I_WEIGHT, 103);
    add_prop(OBJ_I_VOLUME, 76);
    add_prop(OBJ_S_WIZINFO, "A antidote, heals many poisons.\n");
    add_prop(MAGIC_AM_ID_INFO, ({
	"You feel something is good with this potion.\n", 0,
	"This is a antidote potion, it will remove lesser poisons.\n", 20 }) );
}

/*
 * Someone has quaffed us, it's that damned this_player() again!
 */
consume_me()
{
    object *inv;
    int i, strength;
    string *types;

/*
 * Note that we shouldn't do a "deep_inventory".  All poison must be on
 * the top level.  This will allow a gettable living to be poisoned, 
 * where the living does not get cured when the carrier does.
 */
    inv = all_inventory(this_player());
    strength = 30;
    types = ({ "all" });

/* Cycle through each element of the inventory.  If "cure_poison"
 *exists, we must have a poison object, so we call it with the right
 *arguments.
 */
    for (i = 0; i < sizeof(inv); i++ )
    {
    	if (function_exists("cure_poison", inv[i]) == "/std/poison_effect") 
	{
            inv[i]->cure_poison(types, strength);
	    strength = strength / 2;
        }
    }
}

/*
 * This is no magic potion but a herbal mix = can't be dispelled by magic
 */
dispel_magic(magic) { return 0; }

