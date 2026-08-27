/* A weapon should always begin with these statements: */

inherit "/std/weapon";
#include "/sys/wa_types.h"  /* wa_types.h contains some definitions we want */
#include "/sys/macros.h"
#include "/sys/stdproperties.h"

void
create_weapon()
{
    /* Set the name, short description and long description */
    set_name("pole");
    set_long("A big heavy pole.\n");

    /* Now, a player can refere to this weapon as 'weapon' and 'dagger'. To
     * distinguish it from other daggers, we want the player to be able to 
     * use 'small dagger' as an id too.
     */
    set_adj("big");

    /* Now we want to set the 'to hit' value and 'penetration value' */
    set_hit(30);
    set_pen(45);

    /* The weapon type and the type of damage done by this weapon */
    set_wt(W_CLUB); /* It's a club */
    set_dt(W_BLUDGEON); 

    /* Last, how shall it be wielded? */
    set_hands(W_BOTH);

    add_prop(OBJ_I_WEIGHT, 40000); /* 40 kg */
    add_prop(OBJ_I_VALUE, 2000);
    add_prop(OBJ_I_VOLUME, 35000); /* 35 litres */
}

/* This function is called each time the weapon try to hit something */
int
try_hit(object ob) /* ob is the target we will try to hit. */
{
    if (random(2))
    {
/* query_wielded() will give the object who is wielding this object. */

	query_wielded()->catch_msg("You try but doesn't manage to swing " +
		"the big pole.\n");

/* Tell everyone in the room that our wielder didn't manage to hit this time.
 * But don't tell the wielder twice.
 */
	tell_room(environment(query_wielded()), QCTNAME(query_wielded()) + 
		" tries hard but doesn't manage to rise the big pole.\n",
		query_wielded()); /* The last arg say who shall not hear */
	return -1;
    }

    return 1; /* Try hit */
}

/* After we triued to hit something this function is called with the result. */
varargs int
did_hit(int aid, string hdesc, int phurt, object enemy, int dt,
	int phit, int dam)
{
    if (phurt == -1)
    {
	query_wielded()->catch_msg("You manage to hit empty air with the " +
		"pole.\n");
	enemy->catch_msg("You narrowly escape the big pole.\n");
    }
    else if (phurt == 0)
    {
	query_wielded()->catch_msg("You gasps in astonishment when the pole " +
		"just bumps on the " + enemy->query_nonmet_name() + ".\n");
        enemy->catch_msg("To your surprise the big pole just bumps on your " +
		"head instead of crushing it when it hits.\n");
    }
    else
    {
	query_wielded()->catch_msg("The pole falls down on your enemy with a " +
		"crushing sound.\n");
	enemy->catch_msg("You feel the pole hit your head. It was not very " +
		"pleasant.\n");
    }

    return 1;
}

