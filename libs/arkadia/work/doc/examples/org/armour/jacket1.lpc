/*
 * jacket.c
 */

/*
 * The jacket at road1.c
 */
#pragma strict_types

inherit "/std/armour";

#include "ex.h"			/* Always good to have.... */
#include <stdproperties.h>	/* Properties */
#include <wa_types.h>		/* Weapon/armour definitions */
#include <formulas.h>		/* Some formulas used for weight and value */
#include <macros.h>		/* Defines the macro MASTER */

/*
 * The create routine, called create_armour() in this case since we inherit
 * /std/armour.c
 */
void
create_armour()
{
    /*
     * Names and looks are described the same way for armours as other objects
     */
    set_name("jacket");
    set_adj("leather");
    set_long("A soft leather jacket.\n");
    set_short("leather jacket");

    /*
     * The armour class is low, soft leather is about ac 5
     */
    set_ac(4);

    /*
     * We can modify the ac for each damage type there is. The sum of the
     * modifications should be 0. Armour modifiers doesn't have to be set
     * if you don't want to.
     */
    set_am( ({ -2, 1, 1 }) );

    /*
     * The type of the armour has to be set too. Types are defined in
     * /sys/wa_types.h There is also a nice man page for armours. Try
     * 'man armour' if you want to read about it.
     */
    set_at(A_BODY);

    /*
     * Finally give the armour some weight, value and volume. Normally if
     * you don't give the value and weight (or if you set them too low)
     * default values will be used. If you want to see how the formulas
     * are designed you can try 'man F_VALUE_ARMOUR' for instance. Also
     * don't be afraid to use man command to see what's written about
     * properties. F_VALUE_ARMOUR and F_WEIGHT_DEFAULT_ARMOUR are defined
     * in /sys/formulas.h
     */
    add_prop(OBJ_I_VALUE, F_VALUE_ARMOUR(4));
    add_prop(OBJ_I_WEIGHT, F_WEIGHT_DEFAULT_ARMOUR(4, A_BODY));
    add_prop(OBJ_I_VOLUME, 1200);
}

/*
 * We want to make the object recoverable too.....
 * Then we have to define two functions, query_recover() and init_recover()
 * Lucky for us, someone ahs already made sure to support armours to recover,
 * so unless we have added some charges or something to the armour, we'll just
 * use the default saveing and restoring of variables like condition of an
 * armour.
 *
 * query_recover() must be defined in any object that wants to be recoverable
 * it returns a string. MASTER is defined in /sys/macros.h . It returns the
 * filename of this object, which is the file to clone to get a new copy when
 * this object is going to be recovered.
 */
string
query_recover()
{
    return MASTER + ":" + query_arm_recover();
}

/*
 * This function is called when the object is recovered. The argument arg is
 * the part after the ':' as given by query_recover(). It's used to set back 
 * some variables to their right values.
 */
void
init_recover(string arg)
{
    init_arm_recover(arg);
}
