/* An armour should always begin with these statements: */

inherit "/std/armour";
#include "/sys/wa_types.h"  /* wa_types.h contains some definitions we want */
#include "/sys/macros.h"

int times;

void
create_armour()
{
    times = 10; /* How many times this shield can be hit. */

    /* Set the name, short description and long description */
    set_name("shield");
    set_long("It looks very fragile.\n");

    /* Now we want to set the armour class, and perhas a modifier to it */
    set_ac(4);

    /*        impale, slash, bludgeon */
    set_am(({   -2,     1,      1 }));

    /* We also need to set what type of armour this is */
    set_at(A_SHIELD);
}

int
got_hit(int hid, int ph, object att, int dt, int dam)
{
    if (ph > 0)
	times--;

    if (times < 0)
    {
        query_worn()->catch_msg("Your shield breaks!\n");
	tell_room(environment(query_worn()), "The shield of " +
		QTNAME(query_worn()) + " breaks!.\n", query_worn());
        call_out("remove_object", 1);
    }

    return 0;
}


