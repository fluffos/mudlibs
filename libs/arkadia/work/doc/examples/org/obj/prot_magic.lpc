/* A stone, protects the holder from magic
 *
 * Made by Nick
 */

inherit "/std/object";
#include <stdproperties.h>

void
create_object()
{
    set_name("stone");
    set_adj("dull");
    set_long("It looks just like a normal stone.\n");

    add_prop(OBJ_I_VALUE, 100);
    add_prop(OBJ_I_WEIGHT, 235);
    add_prop(OBJ_I_VOLUME, 79);

    add_prop(MAGIC_I_RES_MAGIC, ({ 10, 1 }));
    add_prop(OBJ_S_WIZINFO, "This magic stone will protect you from magic.\n");
    add_prop(MAGIC_AM_MAGIC, ({ 10, "enchantment" }) );
    add_prop(MAGIC_AM_ID_INFO, ({
	"There is something magical about the stone.\n", 1,
	"The stone will protect you magically when hold in some way.\n", 10,
	"If you hold the stone it will protect you against magic.\n", 30 }) );
}

/* This function is called when this object enters another object. */
void
enter_env(object to, object from)
{
    /* We must add this to the player to get query_magic_res() to work */
    if (living(to))
        to->add_prop(MAGIC_I_RES_MAGIC, to->query_prop(MAGIC_I_RES_MAGIC) + 1);

    ::enter_env(to, from);
}

/* This function is called when this object leaves another object. */
void
leave_env(object from, object to)
{
    /* It's nice to clean after oneselves. */
    if (living(from))
        from->add_prop(MAGIC_I_RES_MAGIC,
		from->query_prop(MAGIC_I_RES_MAGIC) - 1);

    ::leave_env(from, to);
}

/* This function is called if someone tries to dispel the magic */
int
dispel_magic() { return 0; } /* Not possible to dispel */

